/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Ceil in Sorted Array (smallest element >= x)
    ============================================================

    INTUITION:
    ----------
    - Array is sorted, so all elements >= x form a contiguous block at the end.
    - Binary search for the leftmost index in that block: whenever arr[mid] is
      a valid candidate (>= x), remember it and try to find an even smaller one
      on the left; otherwise move right.

    STEPS:
    ----------
    1. low = 0, high = n-1, resIdx = -1 (default: no ceil exists).
    2. While low <= high: compute mid.
    3. If arr[mid] < x -> too small, low = mid + 1.
    4. Else -> arr[mid] is a candidate, resIdx = mid, high = mid - 1 (look left
       for something smaller but still >= x).
    5. Return resIdx.

    VARIATIONS TO REMEMBER:
    ----------
    - This is exactly lower_bound(x) in disguise.
    - Floor is the mirror problem: largest element <= x.

    TIME COMPLEXITY  : O(log n) -> search space halves each step
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int resIdx = -1;

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < x) {
                low = mid + 1;
            } else {
                resIdx = mid;
                high = mid - 1;
            }
        }

        return resIdx;
    }
};

int main() {
    return 0;
}