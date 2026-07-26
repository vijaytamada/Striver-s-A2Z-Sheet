/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : Maximum Product Subarray
    ============================================================

    INTUITION:
    ----------
    - Brute force: try every subarray with two nested loops, O(n^2).
    - Optimal: unlike max SUM subarray (Kadane's), product is tricky
      because a negative number can flip a very small (very negative)
      product into the new maximum. So track a running product from
      BOTH directions - left to right AND right to left.
    - Whenever a running product hits 0, reset it to 1 (0 kills everything
      going forward, so restart fresh after it).
    - Doing both directions handles the case where a negative number in
      the middle would otherwise "trap" a good subarray on one side only.

    STEPS:
    ----------
    1. res = INT_MIN, prod = 1.
    2. Left-to-right pass: multiply prod by each element, update res,
       reset prod to 1 whenever it hits 0.
    3. Reset prod = 1, then do the same pass RIGHT-to-LEFT.
    4. Return res (the best of both passes).

    VARIATIONS TO REMEMBER:
    ----------
    - Max SUM subarray (Kadane's) is much simpler since sums don't flip
      sign the way products do, see kadanes_algo.cpp.
    - Alternative approach: track both running MAX and running MIN product
      at each step (min matters because two negatives make a positive).

    TIME COMPLEXITY  : O(n) -> two linear passes (brute force is O(n^2))
    SPACE COMPLEXITY : O(1) -> only a couple of variables used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                res = max(res, prod);
            }
        }
        return res;
    }
};

// Optimal Approach - Kadane's Algorithm
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int prod = 1;

        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            res = max(prod, res);
            if (prod == 0)
                prod = 1;
        }

        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            prod *= nums[i];
            res = max(prod, res);
            if (prod == 0)
                prod = 1;
        }

        return res;
    }
};

int main() {
    return 0;
}