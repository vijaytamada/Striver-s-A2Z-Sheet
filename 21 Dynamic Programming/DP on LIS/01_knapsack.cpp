#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
  public:
    int solve(int idx, int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(idx == 0){
            if(capacity >= wt[idx]){
                return val[idx];
            }
            else{
                return 0;
            }
        }
        
        if(dp[idx][capacity] != -1){
            return dp[idx][capacity];
        }
        
        int notTake = solve(idx-1, capacity, val, wt, dp);
        int take = INT_MIN;
        
        if(capacity >= wt[idx]){
            take = val[idx] + solve(idx-1, capacity - wt[idx], val, wt, dp);
        }
        
        return dp[idx][capacity] = max(take, notTake);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solve(n-1, W, val, wt, dp);
    }
};

// Soln 02: Memoization
class Solution {
  public:
    int solve(int idx, int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(idx == 0){
            if(capacity >= wt[idx]){
                return val[idx];
            }
            else{
                return 0;
            }
        }
        
        if(dp[idx][capacity] != -1){
            return dp[idx][capacity];
        }
        
        int notTake = solve(idx-1, capacity, val, wt, dp);
        int take = INT_MIN;
        
        if(capacity >= wt[idx]){
            take = val[idx] + solve(idx-1, capacity - wt[idx], val, wt, dp);
        }
        
        return dp[idx][capacity] = max(take, notTake);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solve(n-1, W, val, wt, dp);
    }
};

// Soln 03: Tabulation
class Solution {
	public:
	int knapsack(int W, vector<int> &val, vector<int> &wt) {
		// code here
		int n = val.size();
		vector<vector<int>> dp(n, vector<int>(W + 1, 0));
		
		for (int i = 0; i <= W; i++) {
			dp[0][i] = (i >= wt[0] ? val[0] : 0);
		}
		
		for (int idx = 1; idx < n; idx++) {
			for (int capacity = 1; capacity <= W; capacity++) {
				int notTake = dp[idx - 1][capacity];
				int take = INT_MIN;
				
				if (capacity >= wt[idx]) {
					take = val[idx] + dp[idx - 1][capacity - wt[idx]];
				}
				
				dp[idx][capacity] = max(take, notTake);
			}
		}
		
		return dp[n - 1][W];
	}
};


int main()
{
    

    return 0;
}