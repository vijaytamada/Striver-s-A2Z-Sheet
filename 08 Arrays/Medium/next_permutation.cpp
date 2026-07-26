/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Next Permutation
    ============================================================

    INTUITION:
    ----------
    - To get the next lexicographically bigger arrangement, we want to
      change the array as little as possible, and as far right as possible.
    - Scan from the right to find the first index i where nums[i] < nums[i+1]
      (the "break point" - everything after it is in descending order).
    - Swap nums[i] with the smallest element to its right that's still
      bigger than it, then reverse everything after i to get the smallest
      possible arrangement of that suffix (since it was descending, reversing
      makes it ascending).
    - If no break point exists, the array is the last permutation - reversing
      the whole thing gives the first permutation (wrap around).

    STEPS:
    ----------
    1. Find largest index i such that nums[i] < nums[i+1] (scanning from right).
    2. If found, find largest index j > i such that nums[j] > nums[i], swap them.
    3. Reverse the subarray from i+1 to the end (whether or not step 2 ran).

    VARIATIONS TO REMEMBER:
    ----------
    - "Previous permutation" -> mirror logic (find increasing break point,
      swap with largest smaller element, reverse to descending suffix).
    - Related to generating permutations in order / rank of a permutation.

    TIME COMPLEXITY  : O(n) -> a few linear scans over the array
    SPACE COMPLEXITY : O(1) -> in-place swaps and reversal
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2;

        // Step 1: Find first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0) {
            // Step 2: Find element just larger than nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};
int main() {
    return 0;
}