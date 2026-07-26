/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Single Element in a Sorted Array (all others appear twice)
    ============================================================

    INTUITION:
    ----------
    - Before the single element, pairs start at even indices (arr[2i] ==
      arr[2i+1]); after it, the pattern shifts so pairs start at odd indices.
    - Binary search on this "parity of pair-start" property to find the exact
      point where the pattern breaks - that's the single element.

    STEPS:
    ----------
    1. Handle edge cases: n==1, or nums[0]!=nums[1] -> answer is nums[0];
       nums[n-1]!=nums[n-2] -> answer is nums[n-1].
    2. low = 1, high = n-2 (search only the interior).
    3. While low <= high: compute mid.
    4. If nums[mid] differs from both neighbors -> return nums[mid] (found).
    5. If mid is on the "still normal" side (odd mid matching mid-1, or even
       mid matching mid+1) -> eliminate left half, low = mid + 1.
    6. Else -> eliminate right half, high = mid - 1.

    VARIATIONS TO REMEMBER:
    ----------
    - Brute force: single linear scan checking each element against
      neighbors, O(n).
    - XOR trick: XOR every element together, duplicates cancel out leaving
      the single element, O(n) time O(1) space, but doesn't need sorted
      order (this binary search approach specifically exploits sortedness
      for O(log n)).

    TIME COMPLEXITY  : O(log n) -> search space halves each step
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Solution1 Brute Force - One traversal and check for every element if it is unique or not

// Solution2 using XOR - TC: O(N) , SC: O(1)

// Solution3 using - Binary Search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Edge cases
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid is the desired answer
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // we are in the left:
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                // eliminate the left half:
                low = mid + 1;
            }
            // we are in the right:
            else {
                // eliminate the right half:
                high = mid - 1;
            }
        }

        // dummy return statement:
        return -1;
    }
};

int main() {
    return 0;
}