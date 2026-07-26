/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Search in Rotated Sorted Array II (duplicates allowed)
    ============================================================

    INTUITION:
    ----------
    - Same "one half is sorted" trick as the no-duplicates version, but
      duplicates can make nums[low] == nums[mid] == nums[high], so you can't
      tell which half is actually sorted.
    - In that ambiguous case, just shrink both ends by one and retry - you
      lose the O(log n) guarantee but stay correct.

    STEPS:
    ----------
    1. low = 0, high = n-1.
    2. While low <= high: compute mid; if nums[mid] == target -> return true.
    3. If nums[low] == nums[mid] == nums[high] -> low++, high--, continue
       (can't decide which half is sorted).
    4. Else if left half is sorted (nums[low] <= nums[mid]):
       - If target in [nums[low], nums[mid]] -> high = mid - 1.
       - Else -> low = mid + 1.
    5. Else right half is sorted:
       - If target in [nums[mid], nums[high]] -> low = mid + 1.
       - Else -> high = mid - 1.
    6. Return false if not found.

    VARIATIONS TO REMEMBER:
    ----------
    - Differs from the plain (distinct-elements) version only by the extra
      duplicate check; that check makes worst case O(n), e.g. array of all
      same elements like [1,1,1,1,1] with target absent.

    TIME COMPLEXITY  : O(log n) average, O(n) worst case -> duplicates can force
                        low++/high-- one step at a time
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        // Same code as Search in rotated sorted array 1 only thing we add is edge case
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;

            // Edge case - duplicates might be present on both sides after rotation
            // Example - [1,0,1,1,1] target = 0
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

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

        return false;
    }
};

int main() {
    return 0;
}