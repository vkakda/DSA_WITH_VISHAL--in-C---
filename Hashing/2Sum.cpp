//DSA with Vishal - 2 Sum Problem

//Leetcode-1 - https://leetcode.com/problems/two-sum/
//TC- O(n)    - Optimized using Hash Map0000000.

//code👇

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> m; // To store the complement and its index
    vector<int> ans; // New vector to store the result

    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (m.find(complement) != m.end()) {
            ans.push_back(m[complement]);
            ans.push_back(i);
            break;
        }
        m[arr[i]] = i;
    }
    return ans; 
}

int main() {
    vector<int> arr = {5,2,11, 7,  15};
    int target = 9;

    vector<int> result = twoSum(arr, target);
    if (!result.empty()) {
        cout << "Indices of the two numbers are: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers found with the given target sum." << endl;
    }

    return 0;
}

/*
LeetCode - 167 - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
TC-- O(n) - Using Hashing

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m; // To store the number and its index

        for (int i = 0; i < numbers.size(); i++) {
            int complement = target - numbers[i];
            if (m.find(complement) != m.end()) {
                return {m[complement] + 1, i + 1}; // 1-based indexing
            }
            m[numbers[i]] = i;
        }
        return {};
    }
};
*/
