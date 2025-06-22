/* DSA with Vishal - Quick Sort using Recursion & Divide and Conquer.

// Problem Statement:
// Given an array of integers, sort the array using the quick sort algorithm.

// Approach:
// Use recursion to partition the array around a pivot, then sort the subarrays.

// Example:
// Input: arr = [5, 2, 4, 6, 1, 3]
// Output: [1, 2, 3, 4, 5, 6]

// Time Complexity: O(n log n) on average for the quick sort algorithm.
  Note - Time complexity in worst case is O(n^2) when the pivot is always the smallest or largest element.
  for example - [1,2,3,4,5,6] or [6,5,4,3,2,1] and we always choose the last element as pivot.-- (n + (n-1) + (n-2) + ... + 1) = n*(n+1)/2 = O(n^2)

// Space Complexity: O(1).

*/

#include <iostream>
#include <vector>
using namespace std;

// partition function to place pivot at correct position
int partition(vector<int>& arr, int st, int end) { // Time Complexity - O(n)
    int pivot = arr[end];
    int idx = st - 1;
    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

// quickSort function to recursively sort the array
void quickSort(vector<int>& arr, int st, int end) { // Time Complexity - O(n log n) on average
    if (st < end) {
        int pivI = partition(arr, st, end);

        quickSort(arr, st, pivI - 1);   // sort left part
        quickSort(arr, pivI + 1, end);  // sort right part
    }
}

int main() {
    vector<int> arr = {12,31,35,8,32,17};
    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// LeetCode Problem:- 912 // https://leetcode.com/problems/sort-an-array/