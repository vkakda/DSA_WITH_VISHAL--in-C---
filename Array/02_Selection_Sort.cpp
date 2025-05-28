// DSA with Vishal - Selection Sort implementation

/*
STEPS-
1. Start with the first element of the array.
2. Assume the first element is the minimum.
3. Compare the assumed minimum with the next element.
4. If the next element is smaller than the assumed minimum, update the minimum.
5. Continue comparing the assumed minimum with the rest of the elements in the array.
6. After checking all elements, swap the assumed minimum with the first element.
7. Move to the next element and repeat steps 2-6 until the end of the array is reached.
8. The algorithm continues to iterate through the array until all elements are sorted.
*/

//Time complexity: O(n^2) in the worst case, O(n) in the best case (when the array is already sorted).

//code👇

#include <iostream>
using namespace std;


void selectionSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int smallestIndex = i;  // Assume the first element is the smallest
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[smallestIndex]){
                smallestIndex = j;  // Update the index of the smallest element
            }
        }
        swap(arr[i], arr[smallestIndex]);  // Swap the smallest element with the first element of the unsorted part
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
    
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}


// output - 1 2 4 5 8