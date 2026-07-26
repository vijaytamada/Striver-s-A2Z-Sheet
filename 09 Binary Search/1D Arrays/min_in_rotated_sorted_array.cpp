/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Find Minimum in Rotated Sorted Array
    ============================================================

    INTUITION:
    ----------
    - A rotated sorted array splits into two sorted halves around mid; at
      each step exactly one half (low..mid or mid..high) is sorted.
    - The minimum of a sorted half is its first element, so compare that
      against the running answer and discard the sorted half (it can't beat
      the value you already captured), keep searching the unsorted half.

    STEPS:
    ----------
    1. low = 0, high = n-1, res = INT_MAX.
    2. While low <= high: compute mid.
    3. If left half (low..mid) is sorted -> res = min(res, nums[low]),
       move low = mid + 1.
    4. Else right half is sorted -> res = min(res, nums[mid]),
       move high = mid - 1.
    5. Return res.

    VARIATIONS TO REMEMBER:
    ----------
    - "Find K Rotation" is the same logic but returns the INDEX of the
      minimum instead of the value.
    - Search in Rotated Sorted Array reuses the same "identify sorted half"
      trick.

    TIME COMPLEXITY  : O(log n) -> search space halves each step
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        int res = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If left half is sorted
            if (nums[low] <= nums[mid]) {
                res = min(res, nums[low]);
                low = mid + 1;
            } else {
                res = min(res, nums[mid]);
                high = mid - 1;
            }
        }

        return res;
    }
};

int main() {
    return 0;
}