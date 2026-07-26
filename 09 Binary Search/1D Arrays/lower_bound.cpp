/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Lower Bound (first index where arr[i] >= x)
    ============================================================

    INTUITION:
    ----------
    - Array is sorted, so all "candidate" indices (where arr[i] >= x) form a
      contiguous block at the end of the array.
    - Binary search shrinks the window: if arr[mid] >= x, mid COULD be the
      answer so remember it and search left for something even smaller;
      else the answer must be to the right of mid.

    STEPS:
    ----------
    1. low = 0, high = n-1, ans = n (default: not found means "one past end").
    2. While low <= high: compute mid.
    3. If arr[mid] >= x -> ans = mid, move high = mid - 1 (look for a smaller valid index).
    4. Else -> move low = mid + 1.
    5. Return ans.

    VARIATIONS TO REMEMBER:
    ----------
    - Upper bound: first index where arr[i] > x (flip the >= to >).
    - First & last occurrence of x = lower_bound(x) and upper_bound(x) - 1.
    - Search insert position is literally lower_bound.

    TIME COMPLEXITY  : O(log n) -> search space halves each step
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// lower bound - smallest index of element >= target

class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int resIdx = arr.size();

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                resIdx = mid;
                high = mid - 1;
            }
        }

        return resIdx;
    }
};

// Using STL
class Solution2 {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        return lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    }
};


int main() {
    return 0;
}