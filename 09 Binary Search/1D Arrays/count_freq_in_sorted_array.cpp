/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Count Frequency of an Element in Sorted Array
    ============================================================

    INTUITION:
    ----------
    - Since the array is sorted, all occurrences of target sit together in one
      contiguous block.
    - lower_bound gives the first index of that block and upper_bound gives
      the index just past the last occurrence, so the block length is their
      difference.

    STEPS:
    ----------
    1. lb = index of first element >= target (lower_bound).
    2. ub = index of first element > target (upper_bound).
    3. Frequency = ub - lb (0 if target isn't present, since lb == ub then).

    VARIATIONS TO REMEMBER:
    ----------
    - Brute force: linear scan counting matches, O(n).
    - Same idea powers "first and last occurrence" (lb and ub-1).

    TIME COMPLEXITY  : O(log n) -> two binary searches
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Soln - brute force - count occurrences by traversing the array

// Soln - using binary search (lower_bound and upper_bound)
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        
        return ub-lb;
    }
};


int main()
{
    

    return 0;
}