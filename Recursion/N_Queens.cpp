// DSA with Vishal - N-Queens Problem using recursion.

// Problem Statement:
// Solve the N-Queens problem using recursion and backtracking.

// Approach:
// Use a recursive function to place queens on the board such that no two queens threaten each other.

// LeetCode Question:
// Problem: N-Queens (LeetCode #51)
// Link: https://leetcode.com/problems/n-queens/

// Time Complexity: O(n!)
// * - The recursive approach explores all possible configurations, resulting in factorial time complexity.

// Space Complexity: O(n)
// * - The space complexity is determined by the recursion stack and the board representation.

// Example:
// Input: n = 4
// Output: [
//   [".Q..", "...Q", "Q...", "..Q."],
//   ["..Q.", "Q...", "...Q", ".Q.."]
// ]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(const vector<string>& board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
void solveNQueens(int row, int n, vector<string>& board, vector<vector<string>>& solutions) {
    if (row == n) {
        solutions.push_back({board});
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';  // Place queen
            solveNQueens(row + 1, n, board, solutions);
            board[row][col] = '.';  // Backtrack
        }
    }
}

int main() {
    int n = 4;  // Change n to solve for different board sizes
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> solutions;

    solveNQueens(0, n, board, solutions);

    // Print all solutions
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            for (char ch : row) {
                cout << ch << " ";  // Add space between characters for better visibility
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/*
LeetCode Solution:

class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(row + 1, n, board, solutions);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> solutions;
        solve(0, n, board, solutions);
        return solutions;
    }
};
*/