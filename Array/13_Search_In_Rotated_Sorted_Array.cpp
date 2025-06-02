// DSA with Vishal - Search in Rotated Sorted Array

/*
STEPS-
1. Use modified binary search:
   - Find mid.
   - If arr[mid] == key, return mid.
   - If left half is sorted, check if key lies in left half.
   - Else, check if key lies in right half.
2. Adjust start and end accordingly.
3. If not found, return -1.
*/

// Time Complexity: O(log n)
// Space Complexity: O(1)

// code👇

#include <iostream>
#include <vector>
using namespace std;

int searchRotated(vector<int>& arr, int key) {
    int start = 0, end = arr.size() - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == key) return mid;
        if(arr[start] <= arr[mid]) {
            if(key >= arr[start] && key < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        } else {
            if(key > arr[mid] && key <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4,5,6,7,0,1,2};
    int key = 0;
    int idx = searchRotated(arr, key);
    if(idx != -1)
        cout << "Element found at index: " << idx << endl;
    else
        cout << "Element not found." << endl;
    return 0;
}

// Output: Element found at index: 4

/*
// LeetCode: 33
// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) return mid;
            if(nums[start] <= nums[mid]) {
                if(target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                if(target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};
*/
