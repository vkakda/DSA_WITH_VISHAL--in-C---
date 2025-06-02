// DSA with Vishal - Painter's Partition Problem

/*
STEPS-
1. Use binary search on the answer (minimum possible maximum time).
2. For each mid, check if partitioning is possible with given painters.
3. If possible, try for a smaller maximum; else, increase minimum.
*/

// Time Complexity: O(n log(sum))
// Space Complexity: O(1)

// code👇

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& boards, int painters, int maxLen) {
    int count = 1, sum = 0;
    for(int len : boards) {
        if(len > maxLen) return false;
        if(sum + len > maxLen) {
            count++;
            sum = len;
        } else {
            sum += len;
        }
    }
    return count <= painters;
}

int painterPartition(vector<int>& boards, int painters) {
    int low = 0, high = 0, ans = -1;
    for(int len : boards) high += len;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossible(boards, painters, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;
    cout << "Minimum Maximum Length: " << painterPartition(boards, painters) << endl;
    return 0;
}

// Output: Minimum Maximum Length: 60
