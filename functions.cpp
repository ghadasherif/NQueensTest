#include "functions.h"
#include <iostream> 
#include <vector>

using namespace std;

// Function to check if a queen can be placed at a given position
bool isSafe(vector<int>& board, int row, int col) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i] == col) {
            return false;
        }
    }

    // Check if there is a queen on the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i] == j) {
            return false;
        }
    }

    // Check if there is a queen on the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
        if (board[i] == j) {
            return false;
        }
    }

    return true;
}

// Function to solve the N-queens problem using backtracking
void solveNQueens(vector<int>& board, int row, int& count) {
    // Base case: All queens have been placed
    if (row == board.size()) {
        // Print the board configuration
        cout << "Solution " << count << ":\n";
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i] == j) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
        count++;
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            // Place the queen at the current position
            board[row] = col;

            // Recur for the next row
            solveNQueens(board, row + 1, count);

            // Backtrack: Remove the queen from the current position
            board[row] = -1;
        }
    }
}

// Function to solve the N-queens problem and print all solutions
void solveNQueens(int N) {
    vector<int> board(N, -1);
    int count = 1;
    solveNQueens(board, 0, count);
}
