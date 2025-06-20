// DSA with Vishal - Palindrome Partitioning using recursion & backtracking.

// Problem Statement:
// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

// Approach:
// Use recursion and backtracking to explore all possible partitions.
// At each step, try every possible prefix that is a palindrome, then recursively partition the suffix.

// Example:
// Input: s = "aab"
// Output: [
//   ["a","a","b"],
//   ["aa","b"]
// ]

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// getAllParts function to check if a substring is a palindrome
bool isPalindrome( string s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;
}

// getAllParts function to find palindrome partitions
void getAllParts(string s, vector<string>& partitions, vector<vector<string>>& result) {
    if (s.size() == 0) {
        result.push_back(partitions);
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        string prefix = s.substr(0, i + 1);

        if (isPalindrome(prefix)) {
            partitions.push_back(prefix);
            getAllParts(s.substr(i + 1), partitions, result);
            partitions.pop_back();
        }
    }
}

int main() {
    string s = "aab";
    vector<vector<string>> result;
    vector<string> partitions;
    getAllParts(s, partitions, result);

    for (const auto& part : result) {
        cout << "[";
        for (size_t i = 0; i < part.size(); ++i) {
            cout  << part[i] ;
            if (i != part.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}

//LeetCode Problem:- 131 // https://leetcode.com/problems/palindrome-partitioning/
