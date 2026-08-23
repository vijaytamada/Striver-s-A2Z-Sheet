#include <bits/stdc++.h>
using namespace std;

// Soln 01: Plain Recursion
class Solution {
  public:
    int helper(int idx, vector<int>& height){
        if(idx == 0){
            return 0;
        }
        
        int oneJump = helper(idx - 1, height) + abs(height[idx] - height[idx-1]);
        int twoJump = INT_MAX;
        if(idx > 1)
            twoJump = helper(idx - 2, height) + abs(height[idx] - height[idx-2]);
    
        return min(oneJump, twoJump);
    }
  
    int minCost(vector<int>& height) {
        // Code here
        return helper(height.size() - 1, height);
    }
};

// Soln 02: Memoization
class Solution2 {
  public:
    int helper(int idx, vector<int>& height, vector<int>& dp){
        if(idx == 0){
            return 0;
        }

        if(dp[idx] != -1)
            return dp[idx];
        
        int oneJump = helper(idx - 1, height, dp) + abs(height[idx] - height[idx-1]);
        int twoJump = INT_MAX;
        if(idx > 1)
            twoJump = helper(idx - 2, height, dp) + abs(height[idx] - height[idx-2]);
    
        return dp[idx] = min(oneJump, twoJump);
    }
  
    int minCost(vector<int>& height) {
        // Code here
        vector<int> dp(height.size(), -1);
        return helper(height.size() - 1, height, dp);
    }
};

// Soln 03: Tabulation
class Solution3 {
	public:
	int minCost(vector<int>& height) {
		// Code here
		vector<int> dp(height.size(), INT_MAX);
		dp[0] = 0;
		
		for (int i = 1; i<height.size(); i++) {
			int oneJump = dp[i - 1] + abs(height[i] - height[i - 1]);
			int twoJump = INT_MAX;
			if (i > 1) {
				twoJump = dp[i - 2] + abs(height[i] - height[i - 2]);
			}
			
			dp[i] = min(oneJump, twoJump);
		}
		return dp.back();
	}
};

// Soln 04: Space Optimization
class Solution4 {
    public:
    int minCost(vector<int>& height) {
        // Code here
        int prev2 = 0;
        int prev1 = 0;
        
        for(int i=1; i<height.size(); i++){
            int oneJump = prev1 + abs(height[i] - height[i - 1]);
            int twoJump = INT_MAX;
            if(i > 1){
                twoJump = prev2 + abs(height[i] - height[i - 2]);
            }
            
            int curr = min(oneJump, twoJump);
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