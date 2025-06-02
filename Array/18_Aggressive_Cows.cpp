// DSA with Vishal - Aggressive Cows Problem

/*
STEPS-
1. Sort the stalls.
2. Use binary search on the answer (minimum possible distance).
3. For each mid, check if cows can be placed with at least mid distance apart.
4. If possible, try for a larger distance; else, decrease.
*/

// Time Complexity: O(n log(max))
// Space Complexity: O(1)

// code👇

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(vector<int>& stalls, int cows, int minDist) {
    int count = 1, last = stalls[0];
    for(int i = 1; i < stalls.size(); i++) {
        if(stalls[i] - last >= minDist) {
            count++;
            last = stalls[i];
        }
        if(count == cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls.back() - stalls.front(), ans = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canPlaceCows(stalls, cows, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    cout << "Largest Minimum Distance: " << aggressiveCows(stalls, cows) << endl;
    return 0;
}

// Output: Largest Minimum Distance: 3
