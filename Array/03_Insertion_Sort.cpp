// // DSA with Vishal - Insertion Sort implementation

/*
STEPS-
1. Start with the second element of the array (the first element is considered sorted). arr[prev]
2. Compare the current element with the elements in the sorted part of the array (to its left).arr[curr]
3. If the current element is smaller than the previous element, shift the previous element to the right.
4. Continue shifting elements to the right until you find the correct position for the current element.
5. Insert the current element into its correct position in the sorted part of the array.
6. Move to the next element and repeat steps 2-5 until the end of the array is reached.
 7. The algorithm continues to iterate through the array until all elements are sorted.

*/

// Time Complexity: O(n^2) in the worst case, O(n) in the best case (when the array is already sorted).

//code👇

#include <iostream>
using namespace std;


void insertionSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int curr = arr[i];
        int prev = i - 1; 
        // Shift elements of arr[0..i-1], that are greater than curr, to one position ahead of their current position
        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];  // Shift the element to the right
            prev--;  // Move to the previous element
        }
        arr[prev + 1] = curr;  // Insert the current element at its correct position

    }
    
}

void printArray(int arr[], int n) {   // to print the array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}


// output - 1 2 4 5 8