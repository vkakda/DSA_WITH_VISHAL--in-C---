// DSA with Vishal - Book Allocation Problem

/*
STEPS-
1. Use binary search on the answer (minimum possible maximum pages).
2. For each mid, check if allocation is possible with given students.
3. If possible, try for a smaller maximum; else, increase minimum.
*/

// Time Complexity: O(n log(sum))
// Space Complexity: O(1)

// code👇

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& books, int students, int maxPages) {
    int count = 1, sum = 0;
    for(int pages : books) {
        if(pages > maxPages) return false;
        if(sum + pages > maxPages) {
            count++;
            sum = pages;
        } else {
            sum += pages;
        }
    }
    return count <= students;
}

int allocateBooks(vector<int>& books, int students) {
    int low = 0, high = 0, ans = -1;
    for(int pages : books) high += pages;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossible(books, students, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    cout << "Minimum Maximum Pages: " << allocateBooks(books, students) << endl;
    return 0;
}

// Output: Minimum Maximum Pages: 113

/*
// LeetCode: 410 (Split Array Largest Sum)
// Problem Link: https://leetcode.com/problems/split-array-largest-sum/
class Solution {
public:
    bool isPossible(vector<int>& nums, int m, int maxSum) {
        int count = 1, sum = 0;
        for(int n : nums) {
            if(n > maxSum) return false;
            if(sum + n > maxSum) {
                count++;
                sum = n;
            } else {
                sum += n;
            }
        }
        return count <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int low = 0, high = 0, ans = -1;
        for(int n : nums) high += n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(nums, m, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
*/
