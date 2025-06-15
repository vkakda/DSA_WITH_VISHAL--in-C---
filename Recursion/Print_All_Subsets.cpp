// DSA with Vishal - Print All Subsets using recursion.

// Problem Statement:
// Generate all subsets of a given set using recursion.

// Approach:
// Use a recursive function to explore all possible subsets by including or excluding each element.

// LeetCode Question:
// Problem: Subsets (LeetCode #78)
// Link: https://leetcode.com/problems/subsets/

// Time Complexity: O(2^n * n)
// * - The recursive approach generates all possible subsets, resulting in exponential time complexity.
// *
// Space Complexity: O(n)
// * - The space complexity is determined by the recursion stack, which can go as deep as `n`.

// Example:
// Input: {1, 2, 3}
// Output: {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all subsets
void generateSubsets(vector<int>& nums, vector<int>& currentSubset, int index) {
    if (index == nums.size()) {
        // Print the current subset
        cout << "{ ";
        for (int val : currentSubset) {
            cout << val << " ";
        }
        cout << "}" << endl;
        return;
    }

    
    // Include the current element
    currentSubset.push_back(nums[index]);
    generateSubsets(nums, currentSubset, index + 1);
    currentSubset.pop_back(); // Backtrack


    // Exclude the current element
    generateSubsets(nums, currentSubset, index + 1);

}


/*

// Function to generate all unique subsets (Subset II - LeetCode #90)

void generateUniqueSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
    if (i == nums.size()) {
        // Print the current subset
        allSubsets.push_back(ans);
        return;
    }
    
    
    // Include the current element
    ans.push_back(nums[i]);
    generateSubsets(nums, ans, i + 1, allSubsets);

    ans.pop_back(); // Backtrack
    
   
    int idx = i+1;
    while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
 
    // Exclude
    generateSubsets(nums, ans, idx, allSubsets);
   

}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;

        generateSubsets(nums, ans, 0 , allSubsets);

        return allSubsets;
    }
*/



int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> currentSubset;

    generateSubsets(nums, currentSubset, 0);

    return 0;
}