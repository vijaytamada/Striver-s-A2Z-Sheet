#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
  public:
    int helper(int idx, vector<int>& height, int k){
        if(idx == 0){
            return 0;
        }
        
        int minCost = INT_MAX;

        for(int i=1; i<=k; i++){
            if(idx - i >= 0){
                int jumpCost = helper(idx - i, height, k) + abs(height[idx] - height[idx - i]);
                minCost = min(minCost, jumpCost);
            }
        }

        return minCost;
    }

    int minCost(vector<int>& height, int k) {
        // Code here
        return helper(height.size() - 1, height, k);        
    }
};

// Soln 02: Memoization
class Solution2 {
  public:
    int helper(int idx, vector<int>& height, int k, vector<int>& dp){
        if(idx == 0){
            return 0;
        }

        if(dp[idx] != -1)
            return dp[idx];

        int minCost = INT_MAX;

        for(int i=1; i<=k; i++){
            if(idx - i >= 0){
                int jumpCost = helper(idx - i, height, k, dp) + abs(height[idx] - height[idx - i]);
                minCost = min(minCost, jumpCost);
            }
        }

        return dp[idx] = minCost;
    }

    int minCost(vector<int>& height, int k) {
        // Code here
        vector<int> dp(height.size(), -1);
        return helper(height.size() - 1, height, k, dp);        
    }
};

// Soln 03: Tabulation
class Solution3 {
    
  public:
    int minCost(vector<int>& height, int k) {
        // Code here
        vector<int> dp(height.size(), INT_MAX);
        dp[0] = 0;

        for(int i=1; i<height.size(); i++){
            for(int j=1; j<=k; j++){
                if(i - j >= 0){
                    int jumpCost = dp[i - j] + abs(height[i] - height[i - j]);
                    dp[i] = min(dp[i], jumpCost);
                }
            }
        }

        return dp[height.size() - 1];
    }
};

int main()
{
    

    return 0;
}