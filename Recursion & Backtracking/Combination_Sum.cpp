// DSA with Vishal - Combination Sum using recursion & backtracking.

// Problem Statement:
// Given an array of distinct integers and a target value, find all unique combinations where the chosen numbers sum to the target.
// Each number in the array may be used unlimited times in the combination.

// Approach:
// Use recursion and backtracking to explore all possible combinations. At each step, either include the current element or move to the next.

// Example:
// Input: arr = [2, 3, 6, 7], target = 7
// Output: [
//   [2, 2, 3],
//   [7]
// ]

#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> uniqueCombinations;

// Helper function to find combinations
void helper(vector<int>& arr, int idx, int target, vector<int>& current,  vector<vector<int>>& result) {
    if (target == 0) {
        if(uniqueCombinations.find(current) == uniqueCombinations.end()) {
            result.push_back(current);
            uniqueCombinations.insert(current);
        }
        return;
    }
    if (target < 0 || idx == arr.size()) {
        return;
    }

    // Include arr[idx] (can reuse same element, so idx stays the same)
    current.push_back(arr[idx]);
    helper(arr, idx+1, target - arr[idx], current,  result); // include the same element
    helper(arr, idx, target - arr[idx], current, result);  // include multiple times
    current.pop_back();

    // Exclude arr[idx] and move to next
    helper(arr, idx + 1, target, current, result);
}


int main() {
    vector<int> arr = {2, 3,5};
    int target = 8;
    vector<int> current;
    vector<vector<int>> result;
    helper(arr,0, target, current,  result);

    for (auto& comb : result) {
        cout << "[";
        for (int i = 0; i < comb.size(); ++i) {
            cout << comb[i];
            if (i != comb.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}


//LeetCode Problem:- 39 // https://leetcode.com/problems/combination-sum/
