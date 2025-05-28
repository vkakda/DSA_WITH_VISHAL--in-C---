// DSA with Vishal - Product of Array Except Self implementation without using division

/*
STEPS-
1. Initialize two vectors `left` and `right` of the same size as the input array, filled with 1s.
2. Fill the `left` vector such that `left[i]` contains the product of all elements to the left of index `i`.
3. Fill the `right` vector such that `right[i]` contains the product of all elements to the right of index `i`.
4. Initialize a result vector of the same size as the input array.
5. For each index `i`, set `result[i]` to the product of `left[i]` and `right[i]`.
6. Return the result vector.
*/

// Time Complexity: O(n) for both filling left and right vectors, and O(n) for the final result, making it O(n) overall.
// Space Complexity: O(n) for the left and right vectors, and O(n) for the result vector, making it O(n) overall.

// code👇

#include <iostream>
#include <vector>
using namespace std;

 vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        //prefix
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        //suffix
        int suffix = 1;
        for(int i=n-2; i>=0; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }
        return ans;        
    }

int main() {
    vector<int> nums = {1, 2, 3, 4};
    
    vector<int> result = productExceptSelf(nums);
    cout << "Product of Array Except Self: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
// Output: Product of Array Except Self: 24 12 8 6

/*// Leet Code: 238
// Problem Link: https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        //prefix
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        //suffix
        int suffix = 1;
        for(int i=n-2; i>=0; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }
        return ans;        
    }
};
*/