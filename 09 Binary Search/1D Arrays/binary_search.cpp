/*
    ============================================================
    TOPIC   : Binary Search - 1D Arrays
    PROBLEM : Binary Search (find index of target in sorted array)
    ============================================================

    INTUITION:
    ----------
    - Array is sorted, so comparing target with the middle element tells you
      which half it could possibly be in.
    - Discard the half that cannot contain the target each time, halving the
      search space every step.

    STEPS:
    ----------
    1. low = 0, high = n-1.
    2. While low <= high: compute mid = low + (high-low)/2.
    3. If nums[mid] == target -> found, return mid.
    4. If nums[mid] > target -> target must be left, high = mid - 1.
    5. Else -> target must be right, low = mid + 1.
    6. If loop ends without match -> return -1.

    VARIATIONS TO REMEMBER:
    ----------
    - Can also be done directly with STL: binary_search(), lower_bound()==target.
    - Base of almost every other binary search problem in this sheet.

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
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};

// Using STL
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        return upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    }
};

int main() {
    return 0;
}