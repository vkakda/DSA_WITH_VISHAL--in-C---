// DSA with Vishal - Fibonacci Sequence Calculation with recursion.

// Problem Statement:
// Calculate the nth Fibonacci number using recursion.

// Approach:
// Use a recursive function to compute the nth Fibonacci number.

// LeetCode Question:
// Problem: Fibonacci Number (LeetCode #509)
// Link: https://leetcode.com/problems/fibonacci-number/

//  Time Complexity: O(2^n)
//  * - The recursive approach results in exponential time complexity due to repeated calculations 
//  *   of the same subproblems.
//  * 
//  * Space Complexity: O(n)
//  * - The space complexity is determined by the recursion stack, which can go as deep as `n` 
//  *   in the worst case.


// Example: 0,1,1,2,3,5,8,13,...
// Input: 5
// Output: 5





#include <iostream>
using namespace std;

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n; // Base case: if n = 0 or 1.
    }

    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    cout << fibonacci(3) << endl;
    return 0;
}