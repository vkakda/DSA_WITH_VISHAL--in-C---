// DSA with Vishal - Peak Index in a Mountain Array

/*
STEPS-
1. Use binary search to find the peak:
   - If arr[mid] < arr[mid+1], move right.
   - Else, move left.
2. When low == high, that's the peak index.
*/

// Time Complexity: O(log n)
// Space Complexity: O(1)

// code👇

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] < arr[mid+1])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    vector<int> arr = {0,2,4,3,1};
    cout << "Peak Index: " << peakIndexInMountainArray(arr) << endl;
    return 0;
}

// Output: Peak Index: 2

/*
// LeetCode: 852
// Problem Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] < arr[mid+1])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
*/
