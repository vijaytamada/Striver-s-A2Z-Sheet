/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Upper Bound (first index where arr[i] > x)
    ============================================================

    INTUITION:
    ----------
    - Array is sorted, so all "candidate" indices (where arr[i] > x) form a
      contiguous block at the end of the array.
    - Binary search shrinks the window: if arr[mid] > x, mid COULD be the
      answer so remember it and search left for something even earlier;
      else the answer must be to the right of mid.

    STEPS:
    ----------
    1. low = 0, high = n-1, resIdx = n (default: not found means "one past end").
    2. While low <= high: compute mid.
    3. If arr[mid] <= x -> not a candidate yet, low = mid + 1.
    4. Else -> resIdx = mid, move high = mid - 1 (look for an earlier valid index).
    5. Return resIdx.

    VARIATIONS TO REMEMBER:
    ----------
    - Lower bound: first index where arr[i] >= x (flip the > to >=).
    - Last occurrence of x = upper_bound(x) - 1 (when x is present).
    - Count of x in array = upper_bound(x) - lower_bound(x).

    TIME COMPLEXITY  : O(log n) -> search space halves each step
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// upper bound - smallest index of element > target

class Solution1 {
public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int resIdx = arr.size();

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= target) {
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