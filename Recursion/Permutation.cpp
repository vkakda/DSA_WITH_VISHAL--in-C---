// DSA with Vishal - Print All Permutations using recursion.

// Problem Statement:
// Generate all permutations of a given set using recursion.

// Approach:
// Use a recursive function to explore all possible permutations by swapping elements.

// LeetCode Question:
// Problem: Permutations (LeetCode #46)
// Link: https://leetcode.com/problems/permutations/

// Time Complexity: O(n * n!)
// * - The recursive approach generates all possible permutations, resulting in factorial time complexity.

// Space Complexity: O(n)
// * - The space complexity is determined by the recursion stack, which can go as deep as `n`.

// Example:
// Input: {1, 2, 3}
// Output: {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all permutations
void generatePermutations(vector<int>& nums, int index) {
    if (index == nums.size()) {
        // Print the current permutation
        cout << "{ ";
        for (int val : nums) {
            cout << val << " ";
        }
        cout << "}" << endl;
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        // Swap elements to create a new permutation
        swap(nums[index], nums[i]);
        generatePermutations(nums, index + 1);
        swap(nums[index], nums[i]); // Backtrack
    }
}

int main() {
    vector<int> nums = {1, 2, 3};

    generatePermutations(nums, 0);

    return 0;
}


/*
LeetCode Solution:

class Solution {
public:
    
    void getPerms(vector<int>& nums, int index, vector<vector<int>>& ans) {
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            getPerms(nums, index+1, ans);

            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        getPerms(nums, 0, ans);

        return ans;
    }
};


*/