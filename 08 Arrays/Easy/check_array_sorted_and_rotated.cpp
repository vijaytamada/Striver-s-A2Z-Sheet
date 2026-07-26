/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Check if Array Is Sorted and Rotated
    ============================================================

    INTUITION:
    ----------
    - A sorted-then-rotated array can have at most ONE point where an
      element is bigger than the next one (the "break point" where it
      wraps around).
    - Also check the wrap-around pair: last element vs first element.
    - If we count more than 1 such break, it's not a rotated sorted array.

    STEPS:
    ----------
    1. Loop through array, count how many times nums[i] > nums[i+1].
    2. Also check nums[n-1] > nums[0] (the wrap-around case) and count it.
    3. If total count <= 1, it's sorted and rotated (or already sorted).

    VARIATIONS TO REMEMBER:
    ----------
    - Find minimum in rotated sorted array -> binary search variant.
    - Search in rotated sorted array -> modified binary search.

    TIME COMPLEXITY  : O(n) -> single pass over the array
    SPACE COMPLEXITY : O(1) -> no extra space used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
            if (nums[i] > nums[i + 1])
                count++;

        if (nums[n - 1] > nums[0])
            count++;

        return count <= 1;
    }
};

int main() {
    return 0;
}