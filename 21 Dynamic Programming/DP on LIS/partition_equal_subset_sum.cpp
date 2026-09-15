#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
public:
    bool solve(int idx, int target, vector<int> &nums){
        if(target == 0){
            return true;
        }

        if(idx == 0){
            return target == nums[0];
        }

        bool notTake = solve(idx-1, target, nums);
        bool take = false;
        if(target >= nums[idx]){
            take = solve(idx-1, target-nums[idx], nums);
        }

        return take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if(totalSum & 1 == 1){
            return false;
        }

        int n = nums.size();
        return solve(n-1, totalSum/2, nums);
    }
};

// Soln 02: Memoization
class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int idx, int target, vector<int> &nums){
        if(target == 0){
            return true;
        }

        if(idx == 0){
            return target == nums[0];
        }

        if(dp[idx][target] != -1){
            return dp[idx][target];
        }

        bool notTake = solve(idx-1, target, nums);
        bool take = false;
        if(target >= nums[idx]){
            take = solve(idx-1, target-nums[idx], nums);
        }

        return dp[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if(totalSum & 1 == 1){
            return false;
        }

        int n = nums.size();
        this->dp.assign(n, vector<int>(totalSum/2 + 1, -1));

        return solve(n-1, totalSum/2, nums);
    }
};

// Soln 03: Tabulation
class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int idx, int target, vector<int>& nums) {
        if (target == 0) {
            return true;
        }

        if (idx == 0) {
            return target == nums[0];
        }

        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }

        bool notTake = solve(idx - 1, target, nums);
        bool take = false;
        if (target >= nums[idx]) {
            take = solve(idx - 1, target - nums[idx], nums);
        }

        return dp[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((totalSum & 1) == 1) {
            return false;
        }

        int n = nums.size();
        this->dp.assign(n, vector<int>(totalSum / 2 + 1, false));

        dp[0][0] = true;
        dp[0][nums[0]] = true;

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= totalSum/2; target++) {
                bool notTake = dp[idx - 1][target];
                bool take = false;
                if (nums[idx] <= target) {
                    take = dp[idx - 1][target - nums[idx]];
                }

                dp[idx][target] = take || notTake;
            }
        }

        return dp[n - 1][totalSum/2];
    }
};

// Soln 04: Space Optimization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If sum is odd, cannot partition equally
        if (totalSum % 2 == 1) return false;

        int target = totalSum / 2;
        int n = nums.size();

        // DP array: prev[t] means "can we form sum t using elements up to current index?"
        vector<bool> prev(target + 1, false);
        vector<bool> curr(target + 1, false);

        // Base case: sum = 0 is always possible
        prev[0] = true;

        // Initialize with first element
        if (nums[0] <= target) {
            prev[nums[0]] = true;
        }

        // Iterate over remaining elements
        for (int i = 1; i < n; i++) {
            curr[0] = true; // sum = 0 always possible
            for (int t = 1; t <= target; t++) {
                bool notTake = prev[t];
                bool take = false;
                if (nums[i] <= t) {
                    take = prev[t - nums[i]];
                }
                curr[t] = take || notTake;
            }
            prev = curr;
        }

        return prev[target];
    }
};



int main()
{
    

    return 0;
}