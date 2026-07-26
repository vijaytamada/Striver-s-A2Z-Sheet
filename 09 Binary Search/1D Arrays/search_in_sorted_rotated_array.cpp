/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Search in Rotated Sorted Array (distinct elements, no duplicates)
    ============================================================

    INTUITION:
    ----------
    - The array is sorted then rotated, so at any mid, one of the two halves
      (low..mid or mid..high) is guaranteed to be fully sorted.
    - Check if target lies within the sorted half's range; if yes, search
      there, else the target must be in the other (unsorted) half - discard
      the half that can't contain it.

    STEPS:
    ----------
    1. low = 0, high = n-1.
    2. While low <= high: compute mid; if nums[mid] == target -> return mid.
    3. If left half is sorted (nums[low] <= nums[mid]):
       - If target lies within [nums[low], nums[mid]] -> high = mid - 1.
       - Else -> low = mid + 1.
    4. Else right half is sorted:
       - If target lies within [nums[mid], nums[high]] -> low = mid + 1.
       - Else -> high = mid - 1.
    5. Return -1 if not found.

    VARIATIONS TO REMEMBER:
    ----------
    - "_2" variant handles duplicate elements: when nums[low]==nums[mid]==
      nums[high], you can't tell which half is sorted, so shrink both ends
      by one (low++, high--) - worst case degrades to O(n).
    - Find Minimum / Find K Rotation reuse the same "identify sorted half"
      trick without searching for a target.

    TIME COMPLEXITY  : O(log n) -> search space halves each step
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            // left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // right half is sorted
            else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    return 0;
}