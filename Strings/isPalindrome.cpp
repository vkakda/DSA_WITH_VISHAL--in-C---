//DSA with Vishal - Check if a string is a palindrome

// LeetCode problem number: 125 -link: https://leetcode.com/problems/valid-palindrome/

//TC: O(n)

//code👇

#include <iostream>
#include <string>
using namespace std;

bool isAlphaNum(char c) {
    if((tolower(c) >= 'a' && tolower(c) <= 'z') || (c >= '0' && c <= '9')) {
        return true;
    }
    return false;
}

bool isPalindrome( string s) {
    int left = 0, right = s.length() - 1;

    while(left < right) {

       if(!isAlphaNum(s[left])) {
            left++;
            continue;
        } 
        if(!isAlphaNum(s[right])) {
            right--;
            continue;
        }

        if(tolower(s[left]) != tolower(s[right])) {
            return false;
        } 
            left++;
            right--;
        
    }
    
    
    return true;
}


int main() {
    string test = "Ac3?e3c&a";
    if (isPalindrome(test)) {
        cout << test << " is a palindrome." << endl;
    } else {
        cout << test << " is not a palindrome." << endl;
    }
    return 0;
}

