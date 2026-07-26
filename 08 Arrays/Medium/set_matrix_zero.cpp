/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Set Matrix Zeroes (in-place, O(1) extra space)
    ============================================================

    INTUITION:
    ----------
    - If a cell is 0, its entire row and column must become 0.
    - Instead of using extra row/col marker arrays, reuse the matrix's
      own FIRST ROW and FIRST COLUMN as the marker space.
    - Since the first row and first column would overlap at matrix[0][0],
      use two separate boolean flags to remember whether the first row
      and first column themselves originally contained a zero.

    STEPS:
    ----------
    1. Check if first row has any zero -> isFirstRowZero.
    2. Check if first column has any zero -> isFirstColZero.
    3. For the rest of the matrix (i,j starting at 1,1): if matrix[i][j]
       is 0, mark matrix[i][0] = 0 and matrix[0][j] = 0.
    4. Second pass over the same rest-of-matrix region: zero out matrix[i][j]
       if matrix[i][0] == 0 or matrix[0][j] == 0.
    5. Finally, zero out the first row/column themselves if the flags say so.

    VARIATIONS TO REMEMBER:
    ----------
    - Simpler version: use two separate boolean arrays (rows[], cols[])
      of size m and n -> easier to write but O(m+n) space instead of O(1).

    TIME COMPLEXITY  : O(m*n) -> a constant number of passes over the matrix
    SPACE COMPLEXITY : O(1) -> reuses matrix itself for marking, only 2 flags extra
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool isFirstRowZero = false, isFirstColZero = false;

        // Check if first row has zeros
        for (int i = 0; i < cols; i++) {
            if (matrix[0][i] == 0) {
                isFirstRowZero = true;
                break;
            }
        }

        // Check if first cols has zeros
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                isFirstColZero = true;
                break;
            }
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (isFirstRowZero)
            for (int i = 0; i < cols; i++)
                matrix[0][i] = 0;

        if (isFirstColZero)
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
    }
};

int main() {
    return 0;
}