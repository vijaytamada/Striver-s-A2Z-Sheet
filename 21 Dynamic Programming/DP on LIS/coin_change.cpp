#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
public:
    int solve(int amt, vector<int> &coins){
        if(amt == 0){
            return 0;
        }

        if(amt < 0){
            return INT_MAX;
        }

        int res = INT_MAX;

        for(auto &it : coins){
            int minCoins = solve(amt - it, coins);
            if(minCoins != INT_MAX){
                res = min(res, minCoins + 1);
            }
        }

        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int res = solve(amount, coins);
        return res == INT_MAX ? -1 : res;
    }
};

// Soln 02: Memoization
class Solution {
public:
    int solve(int amt, vector<int> &coins, vector<int> &dp){
        if(amt == 0){
            return 0;
        }

        if(amt < 0){
            return INT_MAX;
        }

        if(dp[amt] != -1){
            return dp[amt];
        }

        int res = INT_MAX;

        for(auto &it : coins){
            int minCoins = solve(amt - it, coins, dp);
            if(minCoins != INT_MAX){
                res = min(res, minCoins + 1);
            }
        }

        return dp[amt] = res;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int res = solve(amount, coins, dp);
        return res == INT_MAX ? -1 : res;
    }
};

// Soln 03: Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int amt = 1; amt <= amount; amt++) {
            for (auto& it : coins) {
                if (amt - it >= 0 && dp[amt - it] != INT_MAX) {
                    dp[amt] = min(dp[amt], dp[amt - it] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main()
{
    

    return 0;
}