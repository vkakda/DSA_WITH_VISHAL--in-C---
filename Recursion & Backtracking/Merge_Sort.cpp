// DSA with Vishal - Merge Sort using Recursion & Divide and Conquer.

// Problem Statement:
// Given an array of integers, sort the array using the merge sort algorithm.

// Approach:
// Use recursion to divide the array into halves, sort each half, and then merge the sorted halves.

// Example:
// Input: arr = [5, 2, 4, 6, 1, 3]
// Output: [1, 2, 3, 4, 5, 6]

// Time Complexity: O(n log n) for the merge sort algorithm.
// Space Complexity: O(n) for the temporary array used in merging.



#include <iostream>
#include <vector>
using namespace std;

// merge function to merge two sorted subarrays
void merge(vector<int>& arr, int st, int mid, int end) {  //  Time Complexity - O(n)
   

    vector<int> temp;


    int i = st, j = mid+1;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
    }
}
    while (i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= end){
        temp.push_back(arr[j++]);
    }
        
    for ( int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }
}

// mergeSort function to recursively sort the array
void mergeSort(vector<int>& arr, int st, int end) {  // Time Complexity - O(n) * O(log n) = O(n log n).
    if (st < end) {
    int mid = st + (end - st) / 2;

    mergeSort(arr, st, mid); // for left half
    mergeSort(arr, mid + 1, end); // for Right half

    merge(arr, st, mid, end);
 }
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}

//LeetCode Problem:- 912 // https://leetcode.com/problems/sort-an-array/
