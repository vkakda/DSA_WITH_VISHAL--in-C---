// DSA with Vishal - Subarray Sum Equal K

// Problem Statement:
// Given an array nums and an integer k, find the total number of continuous subarrays 
// whose sum equals to k.

// Approach:
// Use Hashing to store the prefix sum and its frequency.

// Leetcode - 560 - https://leetcode.com/problems/subarray-sum-equals-k/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


//Brute force Approach
int subarraySum1(vector<int>& nums, int k) {
        int n= nums.size();
        int count = 0;

        for(int i = 0; i <n; i++){
            int sum = 0;
            for(int j= i; j<n; j++){
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }


// Optimal Approach - Hashing
 int subarraySum2(vector<int> &nums, int k)  // TC: O(n), SC: O(n)
    {
        int n = nums.size();
        int count = 0;
        vector<int> prefixSum(n, 0);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        unordered_map<int, int> m;
        for (int j = 0; j < n; j++)
        {
            if (prefixSum[j] == k)
                count++;
            int val = prefixSum[j] - k;
            if (m.find(val) != m.end())
            {
                count += m[val];
            }

            if (m.find(prefixSum[j]) == m.end())
            {
                m[prefixSum[j]] = 0;
            }
            m[prefixSum[j]]++;
        }

        return count;
 }

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int result1 = subarraySum1(nums, k);
    int result2 = subarraySum2(nums, k);
    

    cout << "Number of subarrays with sum equal to " << k << ": " << result1 << endl;
    cout << "Number of subarrays with sum equal to " << k << ": " << result2 << endl;

    return 0;
}