// DSA With Vishal - Stock Span Problem

// Problem Statement:
// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock
// and we need to calculate the span of stock’s price for all n days.
// The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days 
// just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.

// Approach:
// Use a stack to keep track of indices of days. For each day, pop from the stack until you find a day with a higher price.
// The span is the difference between the current day and the index of the last higher price day.

// Example:
// Input: price[] = {100, 80, 60, 70, 60, 75, 85}
// Output: 1 1 1 2 1 4 6

// Time Complexity: O(n), where n is the number of days.
// Space Complexity: O(n)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;



int main() {

    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    // Print the price array
    cout << "Prices: ";
    for (int val : price) {
        cout << val << " ";
    }
    cout << endl;


    //solution
    vector<int> ans(price.size(), 0);
        stack<int> st; // stores indices

        for (int i = 0; i < price.size(); i++) {
            while (st.size() > 0 && price[st.top()] <= price[i]) {
                st.pop();
            }
            if(st.empty()){
                ans[i] = i+1;
            } 
            else {
                ans[i] = i-st.top();  //i= prevHigh
            }

            st.push(i);
        }
        
        //print
        cout << "Span: ";
        for(int val: ans){
            cout << val << " ";
        }
        cout << endl;


    return 0;
}

