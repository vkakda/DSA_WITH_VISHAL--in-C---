//DSA with Vishal  - Reverse a string

//LeetCode problem number: 151
//LeetCode problem name: Reverse words in a String
//Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/

//TC - O(n)

//code👇

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


string reverseString (string s){
    int n =  s.length();
    string ans = "";
   
    reverse(s.begin(), s.end());

    for(int i = 0; i<n; i++){
        string word = "";
        while(i<n && s[i] != ' '){
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());
        if(word.length() > 0){
            ans += ' ' + word;
        }
    }
    return ans.substr(1);

}



int main() {
    string s = "hello my name is vishal";
    
    string result = reverseString(s);
    cout << "Reverse string: " << result << endl; 
    
    return 0;
}

