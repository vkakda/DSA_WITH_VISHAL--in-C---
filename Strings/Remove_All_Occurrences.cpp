//DSA with Vishal - Remove All Occurrences of a SubString.

//
// LeetCode problem number: 1910 - link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/ 

// TC: O(n * m) where n is the length of the string and m is the length of the substring

// code👇

#include <iostream>
#include <string>
using namespace std;

string removeOccurrences(string s, string part) {
  while(s.length() >0 && s.find(part) < s.length()) {
    s.erase(s.find(part), part.length());
  } 
    return s;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    
    string result = removeOccurrences(s, part);
    cout << "Resulting string: " << result << endl; 
    
    return 0;
}
// output "dab"