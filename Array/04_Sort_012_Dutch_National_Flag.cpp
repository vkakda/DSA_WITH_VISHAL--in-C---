// DSA with Vishal - Dutch National Flag Problem implementation - 0, 1, 2 sorting

/* The Dutch National Flag problem is a classic algorithmic problem that involves sorting an array containing three distinct values (often represented as 0, 1, and 2) in a single pass.
 The goal is to rearrange the elements in such a way that all 0s come first, followed by all 1s, and finally all 2s.
for ex.- [0, 1, 2, 0, 1, 2, 0, 1, 2] should be sorted to [0, 0, 0, 1, 1, 1, 2, 2, 2]

STEPS_
1. Initialize three pointers: low, mid, and high.
   - low points to the beginning of the array (0 index).
   - mid points to the current element being examined.
   - high points to the end of the array (last index).
2. Start with low = 0, mid = 0, and high = n - 1 (where n is the length of the array).
3. While mid is less than or equal to high, do the following:
   - If the element at mid is 0, swap it with the element at low, increment both low and mid.
   - If the element at mid is 1, just increment mid.
   - If the element at mid is 2, swap it with the element at high and decrement high (do not increment mid in this case).

 */

 // Time Complexity: O(n) - The algorithm makes a single pass through the array, resulting in linear time complexity.
 //Space Complexity: O(1) - The algorithm uses a constant amount of extra space for the pointers.

 //code👇

 #include <iostream>
using namespace std;

void dutchFlagSort(int A[], int n){
    int low = 0, mid = 0, high = n - 1;

    while(mid <= high){
        if(A[mid] == 0){
            swap(A[low], A[mid]);
            low++;
            mid++;
        } else if (A[mid] == 1) {
            mid++;
        } else {
            swap(A[mid], A[high]);
            high--;
            mid--;
        }
    }

   }


int main() {
    int arr[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    dutchFlagSort(arr, n);
    cout << "Sorted array using DNF sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// Output: Sorted array using DNF sort: 0 0 0 1 1 1 2 2 2