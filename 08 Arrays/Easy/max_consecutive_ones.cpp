/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Max Consecutive Ones
    ============================================================

    INTUITION:
    ----------
    - Walk through the array keeping a running count of consecutive 1s.
    - Whenever we hit a 0, the current streak breaks, so compare it with
      the best streak so far and reset the counter.

    STEPS:
    ----------
    1. currCount = 0, count = 0.
    2. For each element: if it's 1, increment currCount.
    3. If it's 0, update count = max(count, currCount) and reset currCount = 0.
    4. After the loop, do one final max check (in case array ends with 1s).

    VARIATIONS TO REMEMBER:
    ----------
    - Max consecutive ones with at most K zeros flipped -> sliding window
      (LeetCode 1004).

    TIME COMPLEXITY  : O(n) -> single pass over the array
    SPACE COMPLEXITY : O(1) -> only counters used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currCount = 0;
        int count = 0;

        for (auto it : nums) {
            if (it == 1)
                currCount++;
            else {
                count = max(currCount, count);
                currCount = 0;
            }
        }

        return max(currCount, count);
    }
};

int main() {
    return 0;
}