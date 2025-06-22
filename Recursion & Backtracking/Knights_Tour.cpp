/* DSA with Vishal - Knight's Tour using Recursion & Backtracking

// Problem Statement:
// Given an N x N chessboard, place a knight on the board and move it so that it visits every square exactly once.
// Print one such tour (if possible).

// Approach:
// Use recursion and backtracking to try all possible knight moves from each cell.
// Mark visited cells and backtrack if stuck.

// Example:
// Input: N = 5, Start at (0, 0)
// Output: A 5x5 board with numbers 1 to 25 showing the knight's path.

// Time Complexity: O(8^(N^2)) in the worst case (exponential).
// Space Complexity: O(N^2) for the board.

*/

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<int>>& board, int r, int c, int n, int expValue) {
    if (r < 0 || r >= n || c < 0 || c >= n || board[r][c] != expValue) {
        return false;
    }

    if (expValue == n * n - 1) {
        return true;
    }

    int ans1 = isValid(board, r - 2, c + 1, n, expValue + 1);
    int ans2 = isValid(board, r - 1, c + 2, n, expValue + 1);
    int ans3 = isValid(board, r + 1, c + 2, n, expValue + 1);
    int ans4 = isValid(board, r + 2, c + 1, n, expValue + 1);
    int ans5 = isValid(board, r + 2, c - 1, n, expValue + 1);
    int ans6 = isValid(board, r + 1, c - 2, n, expValue + 1);
    int ans7 = isValid(board, r - 1, c - 2, n, expValue + 1);
    int ans8 = isValid(board, r - 2, c - 1, n, expValue + 1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

int main() {
    int n = 5;
    vector<vector<int>> board = {
        { 0, 11, 16,  5, 20 },
        {17,  6,  1, 12, 21 },
        {10, 15, 22, 19,  4 },
        { 7, 18,  9,  2, 13 },
        {14,  3,  8, 23, 24 }
    };

    if (isValid(board, 0, 0, n, 0)) {
        cout << "Knight's Tour is valid!" << endl;
    } else {
        cout << "Knight's Tour is NOT valid!" << endl;
    }

    return 0;
}



// LeetCode Problem: 2596- https://leetcode.com/problems/check-knight-tour-configuration/