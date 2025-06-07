// DSA with Vishal - 4Sum

// Problem Statement:
// Given an array nums of n integers, return all the quadruplets [nums[i], nums[j], nums[k], nums[l]]
// such that i != j, i != k, i != l, j != k, j != l, and k != l, and nums[i] + nums[j] + nums[k] + nums[l] == target.

// Note: The solution set must not contain duplicate quadruplets.

// Approach:
// Two-pointer technique after sorting the array.

// Leetcode - 18 - https://leetcode.com/problems/4sum/

// TC: O(n^3), SC: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Optimal Approach - Two-pointer technique
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Sort the array

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for the first element

        for (int j = i + 1; j < n;) {
            int k = j + 1, l = n - 1;
            
            while (k < l) {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                if (sum < target) {
                    k++;
                } else if (sum > target) {
                    l--;
                } else { //sum == tar
                    result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    // Skip duplicates for the third element
                    while (k < l && nums[k] == nums[k - 1]) k++;
                }
            }
            j++;
            while (j < n && nums[j] == nums[j - 1]) j++; // Skip duplicates for the second element
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> quadruplets = fourSum(nums, target);

    cout << "Quadruplets that sum to target:" << endl;
    for (const auto& quad : quadruplets) {
        cout << "[" << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << "]" << endl;
    }

    return 0;
}