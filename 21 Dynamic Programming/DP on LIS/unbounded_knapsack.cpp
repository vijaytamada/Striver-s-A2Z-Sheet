#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
  public:
    int solve(int idx, int cap, vector<int>& val, vector<int>& wt){
        if(idx == 0){
            return (cap / wt[0]) * val[0];
        }
        
        int notTake = solve(idx-1, cap, val, wt);
        
        int take = 0;
        if(cap >= wt[idx]){
            take = val[idx] + solve(idx, cap - wt[idx], val, wt);
        }
        
        return max(notTake, take);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        return solve(n-1, capacity, val, wt);
    }
};

// Soln 02: Memoization
class Solution {
  public:
    int solve(int idx, int cap, vector<int>& val, vector<int>& wt, vector<vector<int>> &dp){
        if(idx == 0){
            return (cap / wt[0]) * val[0];
        }
        
        if(dp[idx][cap] != -1){
            return dp[idx][cap];
        }
        
        int notTake = solve(idx-1, cap, val, wt, dp);
        
        int take = 0;
        if(cap >= wt[idx]){
            take = val[idx] + solve(idx, cap - wt[idx], val, wt, dp);
        }
        
        return dp[idx][cap] = max(notTake, take);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return solve(n-1, capacity, val, wt, dp);
    }
};

// Soln 03: Tabulation
class Solution {
	public:
	int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
		// code here
		int n = val.size();
		vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
		
		for (int i = 0; i <= capacity; i++) {
			dp[0][i] = (i / wt[0]) * val[0];
		}
		
		for (int idx = 1; idx<n; idx++) {
			for (int cap = 1; cap <= capacity; cap++) {
				int notTake = dp[idx - 1][cap];
				
				int take = 0;
				if (cap >= wt[idx]) {
					take = val[idx] + dp[idx][cap - wt[idx]];
				}
				
				dp[idx][cap] = max(notTake, take);
			}
		}
		
		return dp[n - 1][capacity];
	}
};


int main()
{
    

    return 0;
}