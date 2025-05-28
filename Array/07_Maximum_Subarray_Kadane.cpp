// DSA with Vishal - Maximum Subarray (Kadane's Algorithm) implementation

/*
STEPS-
1. Initialize two variables: `maxSum` to a very small value INT_MIN (or negative infinity) and `currentSum` to 0.
2. Iterate through each element of the array:
   - Add the current element to `currentSum`.
   - If `currentSum` is greater than `maxSum`, update `maxSum`.
   - If `currentSum` becomes negative, reset it to 0.
3. After iterating through the entire array, `maxSum` will contain the maximum subarray sum.
*/
// Time Complexity: O(n) 

//code👇

#include <iostream>
#include <vector>
#include <limits.h> // for INT_MIN
using namespace std;

int maxSubArraySum(const vector<int>& nums) {
   int maxSum = INT_MIN; // Initialize to the smallest possible integer
    int currentSum = 0; // Initialize current sum to 0

    for(int val: nums){
        currentSum += val;
        maxSum = max(maxSum, currentSum); // Update maxSum if currentSum is greater
        if(currentSum < 0) {
            currentSum = 0; // Reset currentSum if it becomes negative
        }
    }

    return maxSum;
}


int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int result = maxSubArraySum(nums);
    cout << "Maximum Subarray Sum: " << result << endl; 

    return 0;
}

// Output: 6

/*
// Leets Code: 53
// Problem Link: https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, maxSum = INT_MIN;
        for(int val: nums){
            curr += val;
            maxSum = max(curr, maxSum);
            if(curr < 0 ){
                curr = 0;
            }
        }
        return maxSum;

    }
};
*/