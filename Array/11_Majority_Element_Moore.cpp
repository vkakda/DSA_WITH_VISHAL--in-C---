// DSA with Vishal - Majority Element (Moore's Voting Algorithm)

/*
STEPS-
1. Initialize a candidate and a count variable.
2. Traverse the array:
   - If count is 0, set candidate to the current element.
   - If the current element is the candidate, increment count.
   - Otherwise, decrement count.
3. The candidate at the end is the majority element (if it exists).
*/

// Time Complexity: O(n)
// Space Complexity: O(1)

// code👇

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = -1, count = 0;
    for(int num : nums) {
        if(count == 0) {
            candidate = num;
            count = 1;
        } else if(num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}

// Output: Majority Element: 2

/*
// LeetCode: 169
// Problem Link: https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1, count = 0;
        for(int num : nums) {
            if(count == 0) {
                candidate = num;
                count = 1;
            } else if(num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};
*/
