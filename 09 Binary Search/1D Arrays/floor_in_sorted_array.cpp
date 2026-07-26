/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Floor in Sorted Array (largest element <= x)
    ============================================================

    INTUITION:
    ----------
    - Array is sorted, so all elements <= x form a contiguous block at the
      start of the array.
    - Binary search for the rightmost index in that block: whenever arr[mid]
      is a valid candidate (<= x), remember it and try to find an even larger
      one on the right; otherwise move left.

    STEPS:
    ----------
    1. low = 0, high = n-1, resIdx = -1 (default: no floor exists).
    2. While low <= high: compute mid.
    3. If arr[mid] <= x -> candidate found, resIdx = mid, low = mid + 1 (look
       right for something larger but still <= x).
    4. Else -> too big, high = mid - 1.
    5. Return resIdx.

    VARIATIONS TO REMEMBER:
    ----------
    - Ceil is the mirror problem: smallest element >= x (same code, flip
      condition and shrink direction).

    TIME COMPLEXITY  : O(log n) -> search space halves each step
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int resIdx = -1;

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= x) {
                low = mid + 1;
                resIdx = mid;
            } else {
                high = mid - 1;
            }
        }

        return resIdx;
    }
};

int main() {
    return 0;
}