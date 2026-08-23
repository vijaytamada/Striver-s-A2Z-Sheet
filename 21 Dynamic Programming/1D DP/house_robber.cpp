#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
public:
    int helper(int idx, vector<int> &nums){
        if(idx == 0){
            return nums[0];
        }

        // Pick 
        int pick = nums[idx];
        if(idx - 2 >= 0)
            pick += helper(idx - 2, nums);
        
        // Not pick
        int not_pick = helper(idx - 1, nums);

        return max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        return helper(nums.size() - 1, nums);
    }
};

// Soln 02: Memoization
class Solution {
public:
    int helper(int idx, vector<int> &nums, vector<int> &dp){
        if(idx == 0){
            return nums[0];
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        // Pick 
        int pick = nums[idx];
        if(idx - 2 >= 0)
            pick += helper(idx - 2, nums, dp);
        
        // Not pick
        int not_pick = helper(idx - 1, nums, dp);

        return dp[idx] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums.size() - 1, nums, dp);
    }
};

// Soln 03: Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for(int i=1; i<nums.size(); i++){
            // Pick 
            int pick = nums[i];
            if(i - 2 >= 0)
                pick += dp[i - 2];
            
            // Not pick
            int not_pick = dp[i - 1];

            dp[i] = max(pick, not_pick);
        }

        return dp[nums.size() - 1];
    }
};

// Soln 04: Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = nums[0];

        for(int i=1; i<nums.size(); i++){
            // Pick 
            int pick = nums[i];
            if(i - 2 >= 0)
                pick += prev2;
            
            // Not pick
            int not_pick = prev1;

            int curr = max(pick, not_pick);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main()
{
    

    return 0;
}