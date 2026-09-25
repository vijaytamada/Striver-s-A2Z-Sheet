#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class SolutionRecursion {
public:
    int solve(int idx, int amount, vector<int>& coins) {
        if (amount == 0) return 1;              // check this first
        if (idx < 0 || amount < 0) return 0;

        int take = 0;
        if (amount - coins[idx] >= 0)
            take = solve(idx, amount - coins[idx], coins);   // stay on idx (unlimited supply)

        int skip = solve(idx - 1, amount, coins);

        return take + skip;
    }

    int change(int amount, vector<int>& coins) {
        return solve((int)coins.size() - 1, amount, coins);
    }
};

// Soln 02: Memoization
class SolutionMemo {
public:
    unsigned solve(int idx, int amount, vector<int>& coins, vector<vector<long long>>& dp) {
        if (amount == 0) return 1;
        if (idx < 0 || amount < 0) return 0;
        if (dp[idx][amount] != -1) return (unsigned)dp[idx][amount];

        unsigned take = 0;
        if (amount - coins[idx] >= 0)
            take = solve(idx, amount - coins[idx], coins, dp);

        unsigned skip = solve(idx - 1, amount, coins, dp);

        unsigned res = take + skip;   // unsigned: wraparound is defined
        dp[idx][amount] = res;
        return res;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // long long so -1 can mark "not computed" alongside any unsigned value
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, -1));
        return (int)solve(n - 1, amount, coins, dp);
    }
};

// Soln 03: Tabulation
class SolutionTab {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned>> dp(n, vector<unsigned>(amount + 1, 0));

        // amount 0 can always be made in exactly 1 way (pick nothing)
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int a = 1; a <= amount; a++) {
                unsigned take = 0;
                unsigned skip = 0;

                // take: use coins[i] once more, stay on the same coin
                if (a - coins[i] >= 0) {
                    take = dp[i][a - coins[i]];
                } 

                // skip: don't use coins[i], look at the previous coins
                if (i > 0) {
                    skip = dp[i - 1][a];
                } 

                dp[i][a] = take + skip;
            }
        }

        return (int)dp[n - 1][amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << SolutionRecursion().change(amount, coins) << "\n"; // 4
    cout << SolutionMemo().change(amount, coins) << "\n";      // 4
    cout << SolutionTab().change(amount, coins) << "\n";       // 4
    cout << SolutionSpace().change(amount, coins) << "\n";     // 4
    return 0;
}