/*
    ============================================================
    TOPIC   : Dynamic Programming - 1D DP
    PROBLEM : Climbing Stairs
    ============================================================

    INTUITION:
    ----------
    - To reach step n, the last move was either a single step from
      (n-1) or a double step from (n-2). So ways(n) = ways(n-1) +
      ways(n-2) -- this is literally the Fibonacci recurrence.
    - Three progressively better solutions are shown: plain recursion
      (recomputes the same subproblems exponentially -> TLE),
      memoization (cache each subproblem's answer the first time it's
      computed, top-down), and tabulation (build the answer iteratively
      from the base cases, no recursion at all, bottom-up).

    STEPS (Tabulation - Solution3, the one to actually use):
    ----------
    1. Handle small n directly (n==0 -> 0 here as an edge case,
       n==1 -> 1, n==2 -> 2).
    2. dp[0] = 1, dp[1] = 1 (ways to be at step 0 or 1).
    3. For i from 2 to n: dp[i] = dp[i-1] + dp[i-2].
    4. Return dp[n].

    VARIATIONS TO REMEMBER:
    ----------
    - Classic entry point into 1D DP: recursion -> memoization
      (top-down) -> tabulation (bottom-up) -> further optimized to
      O(1) space by keeping just the last two values instead of a
      full dp array.
    - Same recurrence pattern (dp[i] built from dp[i-1]/dp[i-2] with
      variations) shows up in House Robber, Frog Jump, etc.

    TIME COMPLEXITY  : O(n) for Solution2/Solution3 (O(2^n) for naive Solution1)
    SPACE COMPLEXITY : O(n) for the dp array/memo table (Solution1 uses
                        O(n) recursion stack only, no extra array)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution for Climbing Stairs Problem - TLE
class Solution1 {
public:
    int climbStairs(int n) {
        if (n < 0) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Memoization Solution for Climbing Stairs Problem - Accepted
class Solution2 {
public:
    int helper(int n, vector<int>& dp) {
        // Base cases
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        // If already computed, return cached result
        if (dp[n] != -1)
            return dp[n];

        // Otherwise compute and store
        dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        // Initialize memoization table with -1
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};

// Tabulation Solution for Climbing Stairs Problem - Accepted
class Solution3 {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 0;  // edge case
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // one way to stay at step 0
        dp[1] = 1;  // one way to climb 1 step

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    return 0;
}