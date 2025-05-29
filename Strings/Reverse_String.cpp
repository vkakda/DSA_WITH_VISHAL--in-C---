//DSA with Vishal  - Reverse a string

//LeetCode problem number: 344
//LeetCode problem name: Reverse String
//Problem Link: https://leetcode.com/problems/reverse-string/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//using char string

void reverseString (vector<char>& s){
    int st = 0, end = s.size() - 1;
    while(st<end ){
        swap(s[st++], s[end--]);
    }

}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    for (char c : s) {
        cout << c; // prints "olleh"
    }
    cout << endl;
    return 0;
}

//for string - we can do directly
int main() {
    string s = "hello";
    reverse(s.begin(), s.end());
    cout << s; // prints "olleh"
    cout << endl;
    return 0;
}

