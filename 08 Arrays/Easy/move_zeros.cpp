/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Move Zeroes to End (in-place)
    ============================================================

    INTUITION:
    ----------
    - Classic two-pointer trick: "left" marks the position where the next
      non-zero element should go, "right" scans the array.
    - Whenever right finds a non-zero, swap it into left's position and
      advance left. Zeros naturally get pushed to the back over time.
    - This preserves the relative order of non-zero elements.

    STEPS:
    ----------
    1. left = 0, right = 0.
    2. While right < n: if nums[right] != 0, swap(nums[left], nums[right])
       and increment left.
    3. Always increment right.
    4. By the end, all non-zeros are shifted to the front in order, zeros
       fill the rest.

    VARIATIONS TO REMEMBER:
    ----------
    - Same two-pointer pattern used in remove_duplicates_from_sorted_array.cpp
      and sort_colors.cpp (partitioning in-place).

    TIME COMPLEXITY  : O(n) -> single pass, right visits each element once
    SPACE COMPLEXITY : O(1) -> in-place swaps only
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }

            right++;
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0, 1, 0, 3, 12};
    sol.moveZeroes(arr);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}