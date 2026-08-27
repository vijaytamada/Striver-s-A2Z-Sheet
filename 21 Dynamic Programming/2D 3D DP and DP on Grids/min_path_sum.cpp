#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& grid){
        if(x == 0 && y == 0){
            return grid[x][y];
        }

        if(x < 0 || y < 0){
            return INT_MAX;
        }

        int top = solve(x-1, y, grid);
        int left = solve(x, y-1, grid);

        return min(top, left) + grid[x][y];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return solve(m-1, n-1, grid);
    }
};


// Soln 02: Recursion + Memoization
class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (x == 0 && y == 0) {
            return grid[0][0];
        }
        if (x < 0 || y < 0) {
            return INT_MAX;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int top = solve(x - 1, y, grid, dp);
        int left = solve(x, y - 1, grid, dp);

        dp[x][y] = min(top, left) + grid[x][y];
        return dp[x][y];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, grid, dp);
    }
};


// Soln 03: Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        dp[0][0] = grid[0][0];

        for(int i=1; i<n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i=1; i<m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                int top = dp[i - 1][j];
                int left = dp[i][j - 1];
                dp[i][j] = min(top, left) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};


// Soln 04: Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);
        prev[0] = grid[0][0];

        for(int i=1; i<n; i++){
            prev[i] = prev[i-1] + grid[0][i];
        }

        for(int i=1; i<m; i++){
            vector<int> curr(n, INT_MAX);
            
            curr[0] = prev[0] + grid[i][0]; 

            for(int j=1; j<n; j++){
                int top = prev[j];
                int left = curr[j - 1];
                curr[j] = min(top, left) + grid[i][j];
            }

            prev = curr;
        }

        return prev[n-1];
    }
};


int main()
{
    

    return 0;
}