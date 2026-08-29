#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& matrix) {
        int n = matrix.size();

        if (y < 0 || y >= n)
            return INT_MAX;
        if (x == 0)
            return matrix[0][y];

        int leftDia = solve(x - 1, y - 1, matrix);
        int rightDia = solve(x - 1, y + 1, matrix);
        int up = solve(x - 1, y, matrix);

        return min(up, min(leftDia, rightDia)) + matrix[x][y];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            res = min(res, solve(n - 1, i, matrix));
        }

        return res;
    }
};

// Soln 02: Recursion + Memoization = TLE
class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
        int n = matrix.size();

        if (y < 0 || y >= n)
            return INT_MAX;
        if (x == 0)
            return matrix[0][y];

        if(dp[x][y] != -1){
            return dp[x][y];
        }

        int leftDia = solve(x - 1, y - 1, matrix, dp);
        int rightDia = solve(x - 1, y + 1, matrix, dp);
        int up = solve(x - 1, y, matrix, dp);

        return dp[x][y] = min(up, min(leftDia, rightDia)) + matrix[x][y];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            res = min(res, solve(n - 1, i, matrix, dp));
        }

        return res;
    }
};

// Soln 03: Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        dp[0] = matrix[0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i - 1][j];
                int leftDia = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int rightDia = (j < n - 1) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = min(up, min(leftDia, rightDia)) + matrix[i][j];
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// Soln 04: Space Optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev = matrix[0];

        for (int i = 1; i < n; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                int up = prev[j];
                int leftDia = (j > 0) ? prev[j - 1] : INT_MAX;
                int rightDia = (j < n - 1) ? prev[j + 1] : INT_MAX;

                curr[j] = min(up, min(leftDia, rightDia)) + matrix[i][j];
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};

int main()
{
    

    return 0;
}