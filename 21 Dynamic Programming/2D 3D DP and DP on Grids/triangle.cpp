#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
public:
    int solve(int row, int idx, vector<vector<int>>& tri) {
        if (row == 0) {
            return tri[0][0];
        }

        int up = INT_MAX / 2;
        int diag = INT_MAX / 2;

        if (idx < tri[row - 1].size()) {
            up = solve(row - 1, idx, tri);
        }

        if (idx - 1 >= 0) {
            diag = solve(row - 1, idx - 1, tri);
        }

        return min(up, diag) + tri[row][idx];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int cols = triangle.back().size();

        int ans = INT_MAX;

        for (int i = 0; i < cols; i++) {
            ans = min(ans, solve(rows - 1, i, triangle));
        }

        return ans;
    }
};

// Soln 02: Recursion + Memoization
class Solution {
public:
    int solve(int row, int idx, vector<vector<int>>& tri,
              vector<vector<int>>& dp) {

        // Base case
        if (row == 0) {
            return tri[0][0];
        }

        // Already calculated
        if (dp[row][idx] != -1) {
            return dp[row][idx];
        }

        int up = INT_MAX / 2;
        int diag = INT_MAX / 2;

        if (idx < tri[row - 1].size()) {
            up = solve(row - 1, idx, tri, dp);
        }

        if (idx - 1 >= 0) {
            diag = solve(row - 1, idx - 1, tri, dp);
        }

        return dp[row][idx] = min(up, diag) + tri[row][idx];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int cols = triangle.back().size();

        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        int ans = INT_MAX;

        for (int i = 0; i < cols; i++) {
            ans = min(ans, solve(rows - 1, i, triangle, dp));
        }

        return ans;
    }
};

// Soln 03: Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int cols = triangle.back().size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // Base case
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {

                int up = INT_MAX / 2;
                int diag = INT_MAX / 2;

                // From directly above
                if (j < triangle[i - 1].size()) {
                    up = dp[i - 1][j];
                }

                // From upper-left diagonal
                if (j - 1 >= 0) {
                    diag = dp[i - 1][j - 1];
                }

                dp[i][j] = min(up, diag) + triangle[i][j];
            }
        }

        // Minimum can end anywhere in the last row
        int ans = INT_MAX;

        for (int i = 0; i < cols; i++) {
            ans = min(ans, dp[rows - 1][i]);
        }

        return ans;
    }
};

// Soln 04: Space Optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();

        // Base case
        vector<int> prev(1, triangle[0][0]);

        for (int i = 1; i < rows; i++) {
            vector<int> curr(i + 1, 0);

            for (int j = 0; j < triangle[i].size(); j++) {

                int up = INT_MAX / 2;
                int diag = INT_MAX / 2;

                // From directly above
                if (j < triangle[i - 1].size()) {
                    up = prev[j];
                }

                // From upper-left diagonal
                if (j - 1 >= 0) {
                    diag = prev[j - 1];
                }

                curr[j] = min(up, diag) + triangle[i][j];
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