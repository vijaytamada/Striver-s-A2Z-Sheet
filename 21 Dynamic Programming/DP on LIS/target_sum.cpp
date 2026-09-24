#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
public:
    int solve(int idx, int sum, vector<int>& nums, vector<int>& dp) {
        if (idx == 0) {
            int res = 0;
            res += ((sum - nums[0]) == 0 ? 1 : 0);
            res += ((sum + nums[0]) == 0 ? 1 : 0);
            return res;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int add = solve(idx - 1, sum + nums[idx], nums, dp);
        int sub = solve(idx - 1, sum - nums[idx], nums, dp);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, target, nums, dp);
    }
};

// Soln 02: Memoization
class Solution {
public:
    int solve(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp, int offset) {
        // Sum is outside the possible range
        if (sum < -offset || sum > offset) {
            return 0;
        }

        if (idx == 0) {
            int res = 0;

            if (sum - nums[0] == 0)
                res++;
            if (sum + nums[0] == 0)
                res++;

            return res;
        }

        if (dp[idx][sum + offset] != -1) {
            return dp[idx][sum + offset];
        }

        int add = solve(idx - 1, sum + nums[idx], nums, dp, offset);
        int sub = solve(idx - 1, sum - nums[idx], nums, dp, offset);

        return dp[idx][sum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);
        int offset = total;

        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));

        return solve(n - 1, target, nums, dp, offset);
    }
};

// Soln 03: Tabulation
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int offset = total;

        // dp[i][sum + offset] = number of ways to reach sum using first i elements
        vector<vector<int>> dp(n, vector<int>(2 * total + 1, 0));

        // Base case for first element
        dp[0][offset + nums[0]] += 1;
        dp[0][offset - nums[0]] += 1;

        for (int i = 1; i < n; i++) {
            for (int sum = -offset; sum <= offset; sum++) {
                if (dp[i - 1][sum + offset] > 0) {
                    int addIndex = sum + nums[i] + offset;
                    int subIndex = sum - nums[i] + offset;

                    if (addIndex >= 0 && addIndex <= 2 * total)
                        dp[i][addIndex] += dp[i - 1][sum + offset];

                    if (subIndex >= 0 && subIndex <= 2 * total)
                        dp[i][subIndex] += dp[i - 1][sum + offset];
                }
            }
        }

        // Final answer
        return (target < -offset || target > offset) ? 0 : dp[n - 1][target + offset];
    }
};


int main() {
    return 0;
}