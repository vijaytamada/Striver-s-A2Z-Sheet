/*
    ============================================================
    TOPIC   : Sliding Window & Two Pointers - Medium
    PROBLEM : Max Consecutive Ones III (flip at most k zeros)
    ============================================================

    INTUITION:
    ----------
    - We want the longest window containing at most k zeros (the
      zeros we're "allowed" to flip to 1).
    - Expand right always; shrink left only when zero count exceeds k.
    - The window never actually shrinks in size once it reaches the
      best possible length — it just slides forward.

    STEPS:
    ----------
    1. Expand j, if nums[j] == 0 increment zeros count.
    2. While zeros > k, shrink from left: if nums[i] == 0 decrement
       zeros, then i++.
    3. res = max(res, j - i + 1) at every step.

    VARIATIONS TO REMEMBER:
    ----------
    - Same pattern as "Longest Repeating Character Replacement" but
      alphabet is just {0, 1} and target is always 1.
    - "Fruit Into Baskets" -> same window-shrink pattern with distinct
      count instead of zero count.

    TIME COMPLEXITY  : O(n) -> each pointer moves forward at most n times
    SPACE COMPLEXITY : O(1) -> only a few counters used
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int zeros = 0;
        int res = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0)
                zeros++;

            while (zeros > k) {
                if (nums[i] == 0)
                    zeros--;
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};

int main() {
    return 0;
}