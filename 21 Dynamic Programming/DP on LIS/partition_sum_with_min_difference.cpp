#include <bits/stdc++.h>
using namespace std;

// Soln dereived from subset sum equal k problem - from the tabulation approach
class Solution {
public:
    int minDifference(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();

        // dp[idx][target] = can we form sum 'target' using first idx elements
        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

        // Base case
        dp[0][0] = true;
        if (arr[0] <= totalSum) {
            dp[0][arr[0]] = true;
        }

        // Fill DP
        for (int idx = 1; idx < n; idx++) {
            for (int target = 0; target <= totalSum; target++) {
                bool notTake = dp[idx - 1][target];
                bool take = false;
                if (arr[idx] <= target) {
                    take = dp[idx - 1][target - arr[idx]];
                }
                dp[idx][target] = take || notTake;
            }
        }

        // Find minimum difference by checking all achievable subset sums
        int minDiff = INT_MAX;
        for (int target = 0; target <= totalSum; target++) {
            if (dp[n - 1][target]) {
                int other = totalSum - target;
                minDiff = min(minDiff, abs(other - target));
            }
        }

        return minDiff;
    }
};

int main() {
    return 0;
}