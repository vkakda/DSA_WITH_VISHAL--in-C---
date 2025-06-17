// DSA with Vishal - Rat in a Maze using recursion.

// Problem Statement:
// Find a path for the rat to reach the destination in a maze using recursion and backtracking.

// Approach:
// Use a recursive function to erplore all possible paths in the maze. Mark visited cells and backtrack when necessarc.

// Erample:
// Input: maze = [
//   {1, 0, 0, 0},
//   {1, 1, 0, 1},
//   {0, 1, 0, 0},
//   {1, 1, 1, 1}
// ]
// Output: [
//   {1, 0, 0, 0},
//   {1, 1, 0, 0},
//   {0, 1, 0, 0},
//   {0, 1, 1, 1}
// ]

#include <iostream>
#include <vector>
using namespace std;


// helper to solve the maze
void helper(vector<vector<int>>& mat, int r, int c,  string path, vector<string>& solution) {
    int n = mat.size();

    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1) {
        return; 
    }

    // Base case: If destination is reached
    if (r == n - 1 && c == n - 1) {
        solution.push_back(path);
        return;
    }


        // Mark the cell as visited
        mat[r][c] = -1;

        
        helper(mat, r + 1, c, path+ "D", solution); // Move down
        helper(mat, r - 1, c, path+ "U", solution); // Move up
        helper(mat, r, c - 1, path+ "L", solution); // Move left
        helper(mat, r, c + 1, path+ "R", solution); // Move right

        // Backtrack
        mat[r][c] = 1; // unvisited
    }

// Function to solve the mat
vector<string> solveMaze(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<string> solution;
    string path = "";

    helper(mat, 0, 0, path, solution);

    return solution;
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = solveMaze(mat);
    for(string path : result) {
        cout << path << endl;
    }

    return 0;
}