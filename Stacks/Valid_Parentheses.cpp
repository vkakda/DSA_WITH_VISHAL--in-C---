// DSA With Vishal - Valid Parentheses

// Problem Statement:
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
// determine if the input string is valid.
// An input string is valid if:
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.

// Approach:
// Use a stack to keep track of opening brackets. 
// For every closing bracket, check if the top of the stack is the matching opening bracket.

// Example:
// Input: s = "()[]{}"
// Output: true

// Input: s = "(]"
// Output: false

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(n)

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') { //opening
                st.push(c);
            } else {  //closing
                if (st.size() == 0) return false;
                
                if ((st.top() == '(' && c == ')'  ) ||
                    (st.top() == '{' && c == '}'  ) ||
                    ( st.top() == '[' && c == ']')) {
                        st.pop();
                } else {  //no match
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};

int main() {
    Solution sol;
    string s1 = "({})";
    string s2 = "({}]";
    string s3 = "({}";

    cout << "Input: " << s1 << " -> Output: " << (sol.isValid(s1) ? "true" : "false") << endl;
    cout << "Input: " << s2 << " -> Output: " << (sol.isValid(s2) ? "true" : "false") << endl;
    cout << "Input: " << s3 << " -> Output: " << (sol.isValid(s3) ? "true" : "false") << endl;

    return 0;
}

// LeetCode Problem: 20 // https://leetcode.com/problems/valid-parentheses/
/*
class Solution {
public:
   bool isValid(string s) {
        stack<char> st;
        for (int i= 0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') { //opening
                st.push(s[i]);
            } else {  //closing
                if (st.size() == 0) return false;
                
                if ((st.top() == '(' && s[i] == ')'  ) ||
                    (st.top() == '{' && s[i] == '}'  ) ||
                    ( st.top() == '[' && s[i] == ']')) {
                        st.pop();
                } else {  //no match
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};
*/