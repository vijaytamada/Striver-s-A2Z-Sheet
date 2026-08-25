#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
public:
    int solve(int x, int y){
        if(x == 0 && y == 0){
            return 1;
        }

        if(x < 0 || y < 0){
            return 0;
        }

        int right = solve(x, y-1);
        int down = solve(x-1, y);

        return right + down;
    }

    int uniquePaths(int m, int n) {
        return solve(m-1, n-1);
    }
};

// Soln 02: Recursion + Memoization
class Solution2 {
public:
    int solve(int x, int y, vector<vector<int>> &dp){
        if(x == 0 && y == 0){
            return 1;
        }

        if(x < 0 || y < 0){
            return 0;
        }

        if(dp[x][y] != -1){
            return dp[x][y];
        }

        int right = solve(x, y-1, dp);
        int down = solve(x-1, y, dp);

        return dp[x][y] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp);
    }
};

// Soln 03: Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        for(int i=0; i<m; i++){
            dp[i][0] = 1;
        }

        for(int j=0; j<n; j++){
            dp[0][j] = 1;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                int right = dp[i][j-1];
                int down = dp[i-1][j];
                
                dp[i][j] = right + down;
            }
        }

        return dp[m-1][n-1];
    }
};

// Soln 04: Space Optimization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prevRow(n, 1);
        vector<int> currRow(n, 0);

        for (int i = 1; i < m; i++) {
            currRow[0] = 1;
            for (int j = 1; j < n; j++) {
                int right = currRow[j-1];
                int down  = prevRow[j];
                currRow[j] = right + down;
            }
            prevRow = currRow;
        }

        return prevRow[n-1];
    }
};


int main()
{
    

    return 0;
}