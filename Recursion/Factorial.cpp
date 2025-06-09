// DSA with Vishal - Factorial Calculation with recursion.

// Problem Statement:
// Calculate the factorial of a given number using recursion.

// Approach:
// Use a recursive function to compute the factorial of a number.

// Example:
// Input: 5
// Output: 120

#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    }
    return n * factorial(n - 1); // Recursive case
}
 
int main() {
   
        cout << factorial(5) << endl;
    
    return 0;
}