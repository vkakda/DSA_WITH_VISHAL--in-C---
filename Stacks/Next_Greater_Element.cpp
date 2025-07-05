// DSA With Vishal - Next Greater Element

// Problem Statement:
// Given an array, for each element, find the next greater element to its right in the array.
// If there is no greater element, print -1 for that position.

// Approach:
// Use a stack to keep track of indices whose next greater element hasn't been found yet.
// Traverse the array from right to left. For each element, pop from the stack until you find a greater element or the stack becomes empty.
// The next greater element is the top of the stack (if stack is not empty), else -1.

// Example:
// Input: arr[] = {4, 5, 2, 25}
// Output: 5 25 25 -1

// Time Complexity: O(n), where n is the number of elements.
// Space Complexity: O(n)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

    vector<int> arr = {4, 5, 2, 25};

    // Print the input array
    cout << "Array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    // Solution
    vector<int> ans(arr.size(), -1);
    stack<int> st; // stores elements

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }

    // Print result
    cout << "Next Greater Elements: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}