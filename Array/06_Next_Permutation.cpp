// DSA with Vishal - next Permutation 

/*
STEPS-
1. Find the Pivot:
   - Traverse from right to left and find the first index `i` such that `nums[i] < nums[i + 1]`. this index `i` is the pivot.
    - If no such index exists, the array is in descending order, and we reverse the entire array to get the smallest permutation.
2. Find the Successor(element just greater than pivot):
    - Again, traverse from right to left and find the first index `j` such that `nums[j] > nums[i]`.
    - this will be the element just greater than the nums[i].alignas
3. Swap:
    - Swap nums[i] and nums[j].
4. Reverse the Suffix:
    - Reverse the subarray from index `i + 1` to the end of the array. This will give us the next permutation.
*/

// Time Complexity: O(n + n  + 1 + n) - O(n)

//code👇

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void nextPermutation(vector<int>& A) {  // TC -O(n)  , SC- O(1)
        int n = A.size(),  piv= -1;
        
        for(int i = n-2; i>= 0; i--){
            if(A[i] < A[i+1]){
                piv = i;
                break;
            }
        }
            if(piv == -1){
                reverse(A.begin(),A.end());
                return;
            }

        for(int i = n-1; i > piv; i--){
            if(A[i] > A[piv]){
                swap(A[i], A[piv]);
                break;
            }
        }

        int i= piv +1,  j = n-1;
        while(i<=j) {
            swap(A[i],A[j]);
            i++;
            j--;
        }
        
    }

int main() {
    vector<int> A = {1,2,3};
    
    nextPermutation(A);
    
    cout << "Next permutation: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


// Output: Next permutation: 1 3 2

/*
// Leetcode question - 31 - https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& A) {  // TC -O(n)  , SC- O(1)
        int n = A.size(),  piv= -1;
        
        for(int i = n-2; i>= 0; i--){
            if(A[i] < A[i+1]){
                piv = i;
                break;
            }
        }
            if(piv == -1){
                reverse(A.begin(),A.end());
                return;
            }

        for(int i = n-1; i > piv; i--){
            if(A[i] > A[piv]){
                swap(A[i], A[piv]);
                break;
            }
        }

        int i= piv +1,  j = n-1;
        while(i<=j) {
            swap(A[i],A[j]);
            i++;
            j--;
        }
        
    }
};
*/