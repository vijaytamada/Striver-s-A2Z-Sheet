/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : First and Last Occurrence of an Element in Sorted Array
    ============================================================

    INTUITION:
    ----------
    - All occurrences of target sit in one contiguous block since the array
      is sorted.
    - First occurrence = lower_bound(target); last occurrence = one before
      upper_bound(target).

    STEPS:
    ----------
    1. lb = index of first element >= target (lower_bound).
    2. ub = index of first element > target (upper_bound).
    3. If lb is out of range or nums[lb] != target -> target not present,
       return {-1, -1}.
    4. Else -> return {lb, ub - 1}.

    VARIATIONS TO REMEMBER:
    ----------
    - "Count frequency in sorted array" = ub - lb using the same two calls.
    - Can hand-roll lower_bound/upper_bound instead of STL for interview
      practice.

    TIME COMPLEXITY  : O(log n) -> two binary searches
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (lb == nums.size() || nums[lb] != target) {
            return {-1, -1};
        }

        return {lb, ub - 1};
    }
};

int main() {
    return 0;
}