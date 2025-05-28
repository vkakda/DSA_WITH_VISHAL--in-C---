// DSA with Vishal - Merge 2 Sorted Arrays implementation whithout a new array

/*
    STEPS-
    1. Initialize three pointers: i for the first array, j for the second array, and idx for the last index of the merged array.
    2. Compare the elements at the current pointers of both arrays.
    3. If the element in the first array is smaller, place it at the current index of the merged array and move the pointer of the first array forward.
    4. If the element in the second array is smaller, place it at the current index of the merged array and move the pointer of the second array forward.
    5. Repeat steps 2-4 until one of the arrays is fully traversed.
    6. If there are remaining elements in the first array, copy them to the merged array.
    7. If there are remaining elements in the second array, copy them to the merged array.


*/

// Time Complexity: O(n + m) where n and m are the sizes of the two arrays.

//code👇

#include <iostream>
using namespace std;


void mergeSortedArrays(int A[], int n, int B[], int m) {
    int i = n - 1, j = m - 1, idx = n + m - 1; 

    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[idx--] = A[i--];
        } else {
            A[idx--] = B[j--];
        }
    }
    while (j >= 0) {
        A[idx--] = B[j--];
    }
}

int main() {
    int A[] = {1, 3, 5, 7, 9}; // First sorted array
    int B[] = {2, 4, 6, 8};    // Second sorted array
    int n = sizeof(A) / sizeof(A[0]); // Size of first array
    int m = sizeof(B) / sizeof(B[0]); // Size of second array

    int mergedSize = n + m;
    int mergedArray[mergedSize];

    // Copy elements of A into mergedArray
    for(int i = 0; i < n; i++) {
        mergedArray[i] = A[i];
    }

    // Call mergeSortedArrays with mergedArray as A
    mergeSortedArrays(mergedArray, n, B, m);

    // Print the merged array
    cout << "Merged array: ";
    for(int i = 0; i < n + m; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    return 0;
}


/*
//Leetcode question - 88 - https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {  // TC- O(m+n)
        int idx = m+n-1, i=m-1, j = n-1;

        while(i>=0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[idx--] = nums1[i--];
            } else {
                nums1[idx--] = nums2[j--];
            }
        }

        while(j >= 0){
            nums1[idx--] = nums2[j--];
        }
        
    }
};

*/