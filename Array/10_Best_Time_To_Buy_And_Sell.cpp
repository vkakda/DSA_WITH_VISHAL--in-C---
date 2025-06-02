// DSA with Vishal - Best Time to Buy and Sell Stock

/*
STEPS-
1. Initialize two variables: minPrice to a very large value (INT_MAX) and maxProfit to 0.
2. Iterate through the array of prices:
   - For each price, update minPrice if the current price is lower.
   - Calculate the profit if selling at the current price (current price - minPrice).
   - Update maxProfit if this profit is greater than the current maxProfit.
3. After iterating, maxProfit will contain the maximum profit possible.
*/

// Time Complexity: O(n)
// Space Complexity: O(1)

// code👇

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for(int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}

// Output: Maximum Profit: 5

/*
// LeetCode: 121
// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;
        for(int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};
*/
