// DSA with Vishal - Single Element in a Sorted Array

/*
STEPS-
1. Use binary search:
   - Check if mid is even or odd.
   - Compare arr[mid] with arr[mid^1] (mid^1 toggles last bit: mid+1 if even, mid-1 if odd).
   - If equal, move start to mid+1; else, move end to mid.
2. When start == end, that's the single element.
*/

// Time Complexity: O(log n)
// Space Complexity: O(1)

// code👇

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& arr) {
    int start = 0, end = arr.size() - 1;
    while(start < end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == arr[mid^1])
            start = mid + 1;
        else
            end = mid;
    }
    return arr[start];
}

int main() {
    vector<int> arr = {1,1,2,3,3,4,4,8,8};
    cout << "Single Element: " << singleNonDuplicate(arr) << endl;
    return 0;
}

// Output: Single Element: 2

/*
// LeetCode: 540
// Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] == nums[mid^1])
                start = mid + 1;
            else
                end = mid;
        }
        return nums[start];
    }
};
*/
