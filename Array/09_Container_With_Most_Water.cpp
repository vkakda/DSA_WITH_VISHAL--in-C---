// DSA with Vishal - Container With Most Water

/*
STEPS-
1. Initialize two pointers: start at 0 and end at n-1.
2. Calculate the area between the lines at start and end.
3. Move the pointer pointing to the shorter line inward.
4. Repeat until start < end.
5. Keep track of the maximum area found.
*/

// Time Complexity: O(n)
// Space Complexity: O(1)

// code👇

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int start = 0, end = height.size() - 1;
    int maxArea = 0;
    while(start < end) {
        int h = min(height[start], height[end]);
        int w = end - start;
        maxArea = max(maxArea, h * w);
        if(height[start] < height[end])
            start++;
        else
            end--;
    }
    return maxArea;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Max Area: " << maxArea(height) << endl;
    return 0;
}

// Output: Max Area: 49

/*
// LeetCode: 11
// Problem Link: https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1, maxArea = 0;
        while(start < end) {
            int h = min(height[start], height[end]);
            int w = end - start;
            maxArea = max(maxArea, h * w);
            if(height[start] < height[end])
                start++;
            else
                end--;
        }
        return maxArea;
    }
};
*/
