/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Search Insert Position (index to insert target keeping order)
    ============================================================

    INTUITION:
    ----------
    - The correct insert position for target in a sorted array is exactly
      the first index where arr[i] >= target - i.e. lower_bound.
    - If target exists, that index is where it is; if not, it's exactly
      where it should be inserted to keep the array sorted.

    STEPS:
    ----------
    1. Compute lower_bound(nums.begin(), nums.end(), target).
    2. Subtract nums.begin() to get the index.
    3. Return that index directly.

    VARIATIONS TO REMEMBER:
    ----------
    - Literally the same as the "Lower Bound" problem - no new logic needed.
    - Could hand-roll with low/high/mid instead of STL for interview practice.

    TIME COMPLEXITY  : O(log n) -> STL lower_bound uses binary search
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

int main() {
    return 0;
}