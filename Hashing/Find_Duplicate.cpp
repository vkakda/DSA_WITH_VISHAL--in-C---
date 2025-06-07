// DSA with Vishal - Find Duplicate Number

// Problem Statement:
// Given an array of size n+1, where each element is between 1 and n (inclusive),
// there is exactly one duplicate number. Find the duplicate number.

// Approach:
//slow-fast pointer--linked list
// Using Floyd's Tortoise and Hare (Cycle Detection) algorithm.

//Leetcode - 287 - https://leetcode.com/problems/find-the-duplicate-number/

// TC: O(n), SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Detect the cycle
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find the entrance to the cycle
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow; // The duplicate number
}

int main() {
    vector<int> nums = {3, 1, 3, 4, 2};
    int duplicate = findDuplicate(nums);

    cout << "Duplicate Number: " << duplicate << endl;

    return 0;
}


// Without using Hashing and TC-O(n). TCS & infosys ques.

/*#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& arr) {
    int n = arr.size();
    vector<int> visited(n, 0); // Extra array to remember which numbers we saw

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        if (visited[num] == 1) {
            return num; // This number was already seen
        } else {
            visited[num] = 1; // Mark this number as seen
        }
    }

    return -1; // No duplicate found
}

int main() {
    vector<int> arr = {1, 3, 4, 2, 5, 3};
    cout << "Duplicate number is: " << findDuplicate(arr) << endl;
    return 0;
}*/
