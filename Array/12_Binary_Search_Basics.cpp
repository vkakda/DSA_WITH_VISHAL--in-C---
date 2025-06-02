// DSA with Vishal - Binary Search Basics

/*
STEPS-
1. Initialize two pointers: start = 0, end = n-1.
2. While start <= end:
   - Calculate mid = (start + end) / 2.
   - If arr[mid] == key, return mid.
   - If arr[mid] < key, search in the right half (start = mid + 1).
   - If arr[mid] > key, search in the left half (end = mid - 1).
3. If not found, return -1.
*/

// Time Complexity: O(log n)
// Space Complexity: O(1)

// code👇

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int key) {
    int start = 0, end = arr.size() - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int key = 7;
    int idx = binarySearch(arr, key);
    if(idx != -1)
        cout << "Element found at index: " << idx << endl;
    else
        cout << "Element not found." << endl;
    return 0;
}

// Output: Element found at index: 3
