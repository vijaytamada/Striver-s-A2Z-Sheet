/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Find Peak Element (element greater than both neighbors)
    ============================================================

    INTUITION:
    ----------
    - Treat nums[-1] and nums[n] as -infinity (array boundaries).
    - If nums[mid] is rising compared to nums[mid-1], a peak is guaranteed to
      exist somewhere to the right (since the array must eventually come down
      or end); if falling, a peak exists to the left. This lets you eliminate
      half the array each step even though the array isn't fully sorted.

    STEPS:
    ----------
    1. Handle edge cases: n==1, or nums[0] > nums[1] -> peak at index 0.
    2. If nums[n-1] > nums[n-2] -> peak at index n-1.
    3. low = 1, high = n-2 (interior only, boundaries already handled).
    4. While low <= high: compute mid.
    5. If nums[mid] is greater than both neighbors -> return mid.
    6. Else if rising towards the right (nums[mid] > nums[mid-1]) -> move
       low = mid + 1 (peak lies to the right).
    7. Else -> move high = mid - 1 (peak lies to the left).

    VARIATIONS TO REMEMBER:
    ----------
    - Works even without full sort because we only rely on local slope, not
      global order - classic "binary search on unsorted but bitonic-ish data".

    TIME COMPLEXITY  : O(log n) -> search space halves each step
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1 || nums[0] > nums[1])
            return 0;

        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;

            if (nums[mid] > nums[mid-1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    

    return 0;
}