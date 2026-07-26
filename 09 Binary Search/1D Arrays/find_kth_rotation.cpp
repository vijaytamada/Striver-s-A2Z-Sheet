/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Find K (number of times a sorted array was rotated)
    ============================================================

    INTUITION:
    ----------
    - A rotated sorted array is made of two sorted halves; at every step of
      binary search, exactly one half (low..mid or mid..high) is sorted.
    - The minimum element is the rotation point / pivot, and its index equals
      the number of rotations (k). Track the smallest element seen while
      discarding the sorted half each time.

    STEPS:
    ----------
    1. low = 0, high = n-1, minEle = INT_MAX, minIdx = -1.
    2. While low <= high: compute mid.
    3. If left half (low..mid) is sorted -> update min using nums[low], then
       move low = mid + 1 (the minimum can't be inside a sorted rising half
       except possibly at its start, already captured).
    4. Else right half is sorted -> update min using nums[mid], move
       high = mid - 1.
    5. minIdx is the answer (index of the smallest element = rotation count).

    VARIATIONS TO REMEMBER:
    ----------
    - "Find Minimum in Rotated Sorted Array" is the same problem, just return
      minEle instead of minIdx.
    - Search in Rotated Sorted Array uses the same "one half is sorted" trick.

    TIME COMPLEXITY  : O(log n) -> search space halves each step
    SPACE COMPLEXITY : O(1) -> only a few pointers used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        int low = 0;
        int high = nums.size() - 1;

        int minEle = INT_MAX;
        int minIdx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] < minEle) {
                    minEle = nums[low];
                    minIdx = low;
                }

                low = mid + 1;
            } else {
                if (nums[mid] < minEle) {
                    minEle = nums[mid];
                    minIdx = mid;
                }
                high = mid - 1;
            }
        }

        return minIdx;
    }
};

int main() {
    return 0;
}