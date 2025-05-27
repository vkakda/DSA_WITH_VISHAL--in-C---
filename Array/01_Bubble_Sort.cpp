//DSA with Vishal - Bubble Sort implementation

/*
STEPS-
1. Start with the first element of the array.
2. Compare the current element with the next element.
3. If the current element is greater than the next element, swap them.
4. Swap these two elements.
5. Move to the next element and repeat steps 2-4 until the end of the array is reached.
6. Repeat the entire process for the entire array until no swaps are needed, indicating that the array is sorted.
7. The algorithm continues to iterate through the array until it makes a complete pass without any swaps, indicating that the array is sorted.
it will take (n-1) iterations to sort the array of n elements.
*/


// Time Complexity: O(n^2) in the worst case, O(n) in the best case (when the array is already sorted).



#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n){     //bubble sort function

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }

        }
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
    
    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}