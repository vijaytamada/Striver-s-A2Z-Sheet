#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
public:
    bool solve(int idx, vector<int>& arr, int target) {
        if (target == 0) {
            return true;
        }

        if (idx == 0) {
            return arr[0] == target;
        }

        bool notTake = solve(idx - 1, arr, target);
        bool take = false;
        if (arr[idx] <= target) {
            take = solve(idx - 1, arr, target - arr[idx]);
        }

        return take || notTake;
    }

    bool subsetSumToK(int n, int k, vector<int>& arr) {
        // Write your code here.
        return solve(n - 1, arr, k);
    }
};

// Soln 02: Memoization
class Solution2 {
public:
    bool solve(int idx, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }

        if (idx == 0) {
            return arr[0] == target;
        }

        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }

        bool notTake = solve(idx - 1, arr, target, dp);
        bool take = false;
        if (arr[idx] <= target) {
            take = solve(idx - 1, arr, target - arr[idx], dp);
        }

        return dp[idx][target] = take || notTake;
    }

    bool subsetSumToK(int n, int k, vector<int>& arr) {
        // Write your code here.
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(n - 1, arr, k, dp);
    }
};

// Soln 03: Tabulation
class Solution3 {
public:
    bool subsetSumToK(int n, int k, vector<int>& arr) {
        // Write your code here.
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        for (int target = 0; target <= k; target++) {
            dp[0][target] = (arr[0] == target);
        }

        for (int idx = 0; idx < n; idx++) {
            dp[idx][0] = true;
        }

        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = dp[idx - 1][target];
                bool take = false;
                if (arr[idx] <= target) {
                    take = dp[idx - 1][target - arr[idx]];
                }

                dp[idx][target] = take || notTake;
            }
        }

        return dp[n - 1][k];
    }
};

// Soln 04: Space Optimization
class Solution4 {
public:
    bool subsetSumToK(int n, int k, vector<int>& arr) {
        // Write your code here.
        // DP array: prev[target] means "can we form target using elements up to current index?"
        vector<bool> prev(k + 1, false);

        // Base case: sum = 0 is always possible
        prev[0] = true;

        // Initialize with first element
        if (arr[0] <= k) {
            prev[arr[0]] = true;
        }

        // Iterate over remaining elements
        for (int idx = 1; idx < n; idx++) {
            vector<bool> curr(k + 1, false);
            curr[0] = true;  // sum = 0 always possible

            for (int target = 1; target <= k; target++) {
                bool notTake = prev[target];
                bool take = false;
                if (arr[idx] <= target) {
                    take = prev[target - arr[idx]];
                }
                curr[target] = take || notTake;
            }
            prev = curr;
        }

        return prev[k];
    }
};

int main() {
    return 0;
}