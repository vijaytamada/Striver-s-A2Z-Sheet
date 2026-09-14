#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
public:
    int solve(int row, int col1, int col2, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols) return INT_MIN;

        if (row == rows - 1) {
            if (col1 == col2) return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }

        int curr = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];

        int best = INT_MIN;
        vector<int> dir = {-1, 0, 1};
        for (int d1 : dir) {
            for (int d2 : dir) {
                best = max(best, solve(row + 1, col1 + d1, col2 + d2, grid));
            }
        }

        return curr + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        return solve(0, 0, cols - 1, grid);
    }
};

// Soln 02: Memoization
class Solution2 {
public:
    vector<vector<vector<int>>> dp;

    int solve(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols) return INT_MIN;

        if (row == rows - 1) {
            if (col1 == col2) return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }

        if(dp[row][col1][col2] != -1){
            return dp[row][col1][col2];
        }

        int curr = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];

        int best = INT_MIN;
        vector<int> dir = {-1, 0, 1};
        for (int d1 : dir) {
            for (int d2 : dir) {
                best = max(best, solve(row + 1, col1 + d1, col2 + d2, grid, dp));
            }
        }

        return dp[row][col1][col2] = curr + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        dp.assign(rows, vector<vector<int>> (cols, vector<int>(cols, -1)));

        return solve(0, 0, cols - 1, grid, dp);
    }
};

// Soln 03: Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));

        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == j) {
                    dp[rows - 1][i][j] = grid[rows - 1][i];
                } else {
                    dp[rows - 1][i][j] = grid[rows - 1][i] + grid[rows - 1][j];
                }
            }
        }

        for (int i = rows - 2; i >= 0; i--) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < cols; k++) {
                    int curr = (j == k) ? grid[i][j] : grid[i][j] + grid[i][k];

                    int best = INT_MIN;
                    vector<int> dir = {-1, 0, 1};
                    for (int d1 : dir) {
                        for (int d2 : dir) {
                            int nj = j + d1;
                            int nk = k + d2;
                            if (nj >= 0 && nj < cols && nk >= 0 && nk < cols) {
                                best = max(best, dp[i + 1][nj][nk]);
                            }
                        }
                    }

                    dp[i][j][k] = curr + best;
                }
            }
        }

        return dp[0][0][cols - 1];
    }
};

// Soln 04: Space Optimization


int main()
{
    

    return 0;
}