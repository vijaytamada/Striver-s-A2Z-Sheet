#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
public:
    // Travel from last to first
    int solve(int x, int y, vector<vector<int>>& mat){
        if(x == 0 && y== 0 && mat[0][0] != 1){
            return 1;
        }

        if(x < 0 || y < 0){
            return 0;
        }

        if(mat[x][y] == 1){
            return 0;
        }

        int top = solve(x-1, y, mat);
        int left = solve(x, y-1, mat);

        return top + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return solve(m-1, n-1, obstacleGrid);
    }
};

// Soln 02: Recursion + Memoization
class Solution {
public:
    // Travel from last to first
    int solve(int x, int y, vector<vector<int>>& mat, vector<vector<int>> &dp) {
        if (x == 0 && y == 0 && mat[0][0] != 1) {
            return 1;
        }

        if (x < 0 || y < 0) {
            return 0;
        }

        if (mat[x][y] == 1) {
            return 0;
        }

        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int top = solve(x - 1, y, mat, dp);
        int left = solve(x, y - 1, mat, dp);

        return dp[x][y] = top + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, obstacleGrid, dp);
    }
};

// Soln 03: Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Start cell
        dp[0][0] = (obstacleGrid[0][0] == 1 ? 0 : 1);

        // First column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i - 1][0]; // only reachable if the cell above is reachable
            }
        }

        // First row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                dp[0][j] = 0;
            } else {
                dp[0][j] = dp[0][j - 1]; // only reachable if the cell to the
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    int top = dp[i - 1][j];
                    int left = dp[i][j - 1];
                    dp[i][j] = top + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

// Soln 04: Space Optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prevRow(n, 0);

        // Initialize first row
        prevRow[0] = (obstacleGrid[0][0] == 1 ? 0 : 1);
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                prevRow[j] = 0;
            } else {
                prevRow[j] = prevRow[j - 1];
            }
        }

        // Process remaining rows
        for (int i = 1; i < m; i++) {
            vector<int> currRow(n, 0);

            // First column of current row
            if (obstacleGrid[i][0] == 1) {
                currRow[0] = 0;
            } else {
                currRow[0] = prevRow[0];
            }

            // Fill rest of row
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    currRow[j] = 0;
                } else {
                    int top = prevRow[j];
                    int left = currRow[j - 1];
                    currRow[j] = top + left;
                }
            }

            prevRow = currRow; // move to next row
        }

        return prevRow[n - 1];
    }
};


int main()
{
    

    return 0;
}