/* DSA with Vishal - Count Inversions using Recursion & Divide and Conquer (Merge Sort).

// Problem Statement:
// Given an array of integers, count the number of inversions in the array.
// An inversion is a pair (i, j) such that i < j and arr[i] > arr[j].

// Approach:
// Use a modified merge sort algorithm to count inversions while sorting the array.

// Example:
// Input: arr = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The inversions are (2,1), (4,1), (4,3).

// Time Complexity: O(n log n) for the merge sort based inversion count.
// Space Complexity: O(n) for the temporary array used in merge.

*/

#include <iostream>
#include <vector>
using namespace std;


//Brute Force Approach - O(n^2) - Not Efficient
int countInversionsBruteForce(vector<int>& arr) {
    int InvCount = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                InvCount++;
            }
        }
    }
    return InvCount;
}



// Merge function to count inversions and merge two sorted halves
int mergeAndCount(vector<int>& arr, int st, int mid, int end) { // Time Complexity - O(n)
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1); // All remaining elements in st half are greater
        }
    }
    while (i <= mid){
        temp.push_back(arr[i]);   
        i++;
    }
    while (j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }
    return invCount;
}

// Recursive function to count inversions using merge sort
int countInversions(vector<int>& arr, int st, int end) { // Time Complexity - O(n log n)
    if (st < end) {
        int mid = st + (end - st) / 2;

       int invLeftCount = countInversions(arr, st, mid);        // st half
       int invRightCount = countInversions(arr, mid + 1, end);   // end half
       int invCount = mergeAndCount(arr, st, mid, end);   // Merge and count

       return invLeftCount + invRightCount + invCount; // Total inversions
    }

    return 0;
}


int main() {
    vector<int> arr = {6,3,5,2,7,1};
    int inversionCount = countInversions(arr, 0, arr.size() - 1);

    // Uncomment the line below the brute force approach
    // int inversionCount = countInversionsBruteForce(arr);

    cout << "Number of inversions: " << inversionCount << endl;

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// LeetCode Problem:- 315 // https://leetcode.com/problems/count-of-smaller-numbers-after-self/