//DSA with Vishal- Palindrome Number - 353

//LeetCode - 9 👇-- https://leetcode.com/problems/palindrome-number/

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int revNum = 0;

        while(x != 0 ){
            int dig = x % 10;

            if(revNum > INT_MAX/10 || revNum < INT_MIN/10){
                return 0;
            }
            revNum = (revNum * 10) + dig;
            
            x = x/10;
        }
        return revNum;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x != 0 && x % 10 == 0) return false; // numbers ending with 0 (except 0 itself) are not palindrome

        int revNum = 0, original = x;
        while(x > 0) {
            revNum = revNum * 10 + x % 10;
            x /= 10;
        }
        return original == revNum;
    }
};

int main() {
    Solution sol;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if(sol.isPalindrome(num)) {
        cout << num << " is a palindrome number." << endl;
    } else {
        cout << num << " is not a palindrome number." << endl;
    }
    return 0;
}
