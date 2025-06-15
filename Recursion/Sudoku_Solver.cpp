// DSA with Vishal - Sudoku Solver using recursion.

// Problem Statement:
// Solve the Sudoku puzzle using recursion and backtracking.
 
// Approach:
// Use a recursive function to fill the board such that all rows, columns, and subgrids contain unique numbers from 1 to 9.

// LeetCode Question:
// Problem: Sudoku Solver (LeetCode #37)
// Link: https://leetcode.com/problems/sudoku-solver/

// Time Complexity: O(9^(n*n))
// * - The recursive approach explores all possible configurations, resulting in exponential time complexity.

// Space Complexity: O(n*n)
// * - The space complexity is determined by the board representation and recursion stack.

// Example:
// Input: board = [
//   ["5","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: [
//   ["5","3","4","6","7","8","9","1","2"],
//   ["6","7","2","1","9","5","3","4","8"],
//   ["1","9","8","3","4","2","5","6","7"],
//   ["8","5","9","7","6","1","4","2","3"],
//   ["4","2","6","8","5","3","7","9","1"],
//   ["7","1","3","9","2","4","8","5","6"],
//   ["9","6","1","5","3","7","2","8","4"],
//   ["2","8","7","4","1","9","6","3","5"],
//   ["3","4","5","2","8","6","1","7","9"]
// ]

#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing a number at (row, col) is valid
bool isValid(const vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        // Check row and column
        if (board[row][i] == num || board[i][col] == num) return false;

        // Check 3x3 subgrid
        int subRow = 3 * (row / 3) + i / 3;
        int subCol = 3 * (col / 3) + i % 3;
        if (board[subRow][subCol] == num) return false;
    }
    return true;
}

// Recursive function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;  // Place number
                        if (solveSudoku(board)) return true;
                        board[row][col] = '.';  // Backtrack
                    }
                }
                return false;  // No valid number found
            }
        }
    }
    return true;  // Puzzle solved
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (solveSudoku(board)) {
        // Print solved board
        for (const auto& row : board) {
            for (char ch : row) {
                cout << ch << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}

/*
LeetCode Solution:

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            //for horizontal            // for verticle
            if (board[row][i] == num || board[i][col] == num) return false;
        }
        //for 3x3 grid
        int srow = (row / 3)* 3;
        int scol = (col / 3)* 3;

        for(int i=srow; i<=srow+2; i++){
            for(int j=scol; j<=scol+2; j++){
                if (board[i][j] == num) return false;
            }
        }
            
        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {
        if(row == 9) return true;

        int nextRow = row, nextCol= col+1;
        if(nextCol == 9){
            nextRow = row+1;
            nextCol = 0;
        }

        if(board[row][col] != '.'){
            return solve(board, nextRow, nextCol);
        }

        //digit placement
       for (char num = '1'; num <= '9'; num++) {
          if (isValid(board, row, col, num)) {
              board[row][col] = num;
             if (solve(board,nextRow,nextCol)) return true;

             board[row][col] = '.';
            }
        }
            return false;
     }
        

    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};
*/