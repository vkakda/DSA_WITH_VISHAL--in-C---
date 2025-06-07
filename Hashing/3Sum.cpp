// DSA with Vishal - 3Sum

// Problem Statement:
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Note: The solution set must not contain duplicate triplets.

// Approach:
// Two-pointer technique after sorting the array.

// Leetcode - 15 - https://leetcode.com/problems/3sum/

// TC: O(n^2), SC: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//BruteForce Approach

vector<vector<int>> threeSum1(vector<int>& nums) {
     int n = nums.size();
        vector<vector<int>> ans;

        set<vector<int>> s;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> trip = {nums[i], nums[j], nums[k]};
                        sort(trip.begin(), trip.end());

                        if (s.find(trip) == s.end()) {
                            s.insert(trip);
                            ans.push_back(trip);
                        }
                    }
                }
            }
        }
        return ans;
}

//Approach with Hashing
vector<vector<int>> threeSum2(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(), nums.end()); // Sort the array to handle duplicates easily
        
       set<vector<int>> uniqueTriplet;

       for(int i=0; i<n; i++){
           if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for the first element

           int tar = -nums[i];
           set<int> s;
           for(int j=i+1; j<n; j++){
               int third = tar - nums[j];
               if(s.find(third) != s.end()){
                   uniqueTriplet.insert({nums[i], nums[j], third});
               }
               s.insert(nums[j]);
           }
       }
       vector<vector<int>> ans(uniqueTriplet.begin(), uniqueTriplet.end());
       return ans;
}


//2 pointer Approach - optimal
vector<vector<int>> threeSum3(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Sort the array

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for the first element

        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0)  {
                k--;
            } else {
                result.push_back({nums[i], nums[j], nums[k]});
                j++; 
                k--;

                // Skip duplicates for the second and third elements
                while (j < k && nums[j] == nums[j - 1]) ++j;
                while (j < k && nums[k] == nums[k + 1]) --k;
            } 
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = threeSum3(nums);

    cout << "Triplets that sum to zero:" << endl;
    for (const auto& triplet : triplets) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}