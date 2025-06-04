// DSA with Vishal - Find Missing and Repeating Numbers

// Problem Statement:
// Given an array of size n, where each element is between 1 and n (inclusive), 
// one number is missing, and one number is repeated. Find both numbers.

// Approach:
// Using mathematical properties to calculate the missing and repeating numbers.
// TC: O(n), SC: O(1)

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    vector<int> ans;
    unordered_set<int> s;
    int n = grid.size();
    int a, b;

    int expSum = 0, actualSum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            actualSum += grid[i][j];

            if (s.find(grid[i][j]) != s.end()) {
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    expSum = (n * n) * (n * n + 1) / 2;
    b = expSum + a - actualSum;
    ans.push_back(b);

    return ans;
}

int main() {
    vector<vector<int>> grid = {
        {9, 2, 3},
        {4, 9, 6},
        {7, 8, 5}
    };

    vector<int> result = findMissingAndRepeatedValues(grid);
    cout << "Repeated: " << result[0] << ", Missing: " << result[1] << endl;

    return 0;
}


/*
Alternate Approach:
Using XOR to find the missing and repeating numbers.
TC: O(n), SC: O(1)

vector<int> findErrorNums(vector<int>& nums) {
    int xorAll = 0, xorNums = 0, n = nums.size();
    for (int i = 1; i <= n; i++) xorAll ^= i;
    for (int num : nums) xorNums ^= num;

    int xorResult = xorAll ^ xorNums; // XOR of missing and repeating
    int rightmostBit = xorResult & -xorResult;

    int missing = 0, repeating = 0;
    for (int i = 1; i <= n; i++) {
        if (i & rightmostBit) missing ^= i;
        else repeating ^= i;
    }
    for (int num : nums) {
        if (num & rightmostBit) missing ^= num;
        else repeating ^= num;
    }

    for (int num : nums) {
        if (num == missing) swap(missing, repeating);
    }

    return {missing, repeating};
}

// Approach using unordered_set:
// TC: O(n), SC: O(n)



*/