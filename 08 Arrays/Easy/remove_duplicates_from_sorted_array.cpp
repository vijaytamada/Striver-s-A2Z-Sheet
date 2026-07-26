/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Remove Duplicates from Sorted Array (in-place)
    ============================================================

    INTUITION:
    ----------
    - Since the array is SORTED, duplicates are always adjacent.
    - Two pointers: "left" tracks the last position of a unique run,
      "right" scans ahead comparing with its neighbor.
    - Only when nums[right] != nums[right+1] do we know we've found the
      end of a unique run, so we place it at left and move left forward.

    STEPS:
    ----------
    1. left = 0, right = 0.
    2. While right < n-1: if nums[right] != nums[right+1], swap into
       nums[left] and increment left.
    3. Increment right regardless.
    4. Place nums.back() (the last unique element) at nums[left].
    5. Return left + 1 as the count of unique elements.

    VARIATIONS TO REMEMBER:
    ----------
    - If array is unsorted, need hashing/sorting first - two pointers only
      works because duplicates are guaranteed adjacent here.
    - "Remove duplicates II" (allow at most 2 copies) -> tweak the
      comparison window slightly.

    TIME COMPLEXITY  : O(n) -> single pass over the array
    SPACE COMPLEXITY : O(1) -> in-place swaps only
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 0;

        while (right < nums.size() - 1) {
            if (nums[right] != nums[right + 1]) {
                swap(nums[left], nums[right]);
                left++;
            }

            right++;
        }

        nums[left] = nums.back();
        return left + 1;
    }
};

int main() {
    return 0;
}