#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// ----------------------------------------------------
// Soln 01: Pure Recursion (Exponential, for learning)
// ----------------------------------------------------
class RecursionSolution {
public:
    int solve(int idx, int target, vector<int>& arr) {
        if (target == 0) return 1;   // empty subset always valid
        if (idx == 0) {
            if (arr[0] == 0 && target == 0) return 2; // {} and {0}
            return (arr[0] == target) ? 1 : 0;
        }

        int notTake = solve(idx - 1, target, arr);
        int take = 0;
        if (target >= arr[idx]) {
            take = solve(idx - 1, target - arr[idx], arr);
        }

        return (take + notTake) % MOD;
    }

    int findWays(vector<int>& arr, int k) {
        return solve(arr.size() - 1, k, arr);
    }
};

// ----------------------------------------------------
// Soln 02: Memoization (Top-Down DP)
// ----------------------------------------------------
class MemoSolution {
public:
    int solve(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return 1;
        if (idx == 0) {
            if (arr[0] == 0 && target == 0) return 2;
            return (arr[0] == target) ? 1 : 0;
        }

        if (dp[idx][target] != -1) return dp[idx][target];

        int notTake = solve(idx - 1, target, arr, dp);
        int take = 0;
        if (target >= arr[idx]) {
            take = solve(idx - 1, target - arr[idx], arr, dp);
        }

        return dp[idx][target] = (take + notTake) % MOD;
    }

    int findWays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(n - 1, k, arr, dp);
    }
};

// ----------------------------------------------------
// Soln 03: Tabulation (Bottom-Up DP)
// ----------------------------------------------------
class TabulationSolution {
public:
    int findWays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        // base case: sum = 0 is always possible
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // initialize first row
        if (arr[0] <= k) {
            dp[0][arr[0]] += 1;  // += handles arr[0] == 0 correctly
        }

        for (int idx = 1; idx < n; idx++) {
            for (int target = 0; target <= k; target++) {
                int notTake = dp[idx - 1][target];
                int take = 0;
                if (target >= arr[idx]) {
                    take = dp[idx - 1][target - arr[idx]];
                }
                dp[idx][target] = (take + notTake) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};

// ----------------------------------------------------
// Driver
// ----------------------------------------------------
int main() {
    vector<int> arr = {1, 1, 4, 5};
    int k = 5;

    RecursionSolution rec;
    MemoSolution memo;
    TabulationSolution tab;

    cout << "Recursion: " << rec.findWays(arr, k) << endl;
    cout << "Memoization: " << memo.findWays(arr, k) << endl;
    cout << "Tabulation: " << tab.findWays(arr, k) << endl;

    return 0;
}
