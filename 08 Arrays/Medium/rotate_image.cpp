/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Rotate Image (rotate NxN matrix 90 degrees clockwise, in-place)
    ============================================================

    INTUITION:
    ----------
    - A 90-degree clockwise rotation can be broken into two simple steps:
      transpose the matrix (flip across the main diagonal), then reverse
      each row.
    - This avoids needing a second matrix - everything happens in-place.

    STEPS:
    ----------
    1. Transpose: for i from 0..n-1, for j from 0..i-1, swap matrix[i][j]
       with matrix[j][i] (only need to do it for one triangle).
    2. Reverse each row of the transposed matrix.

    VARIATIONS TO REMEMBER:
    ----------
    - Counter-clockwise rotation -> transpose then reverse each COLUMN
      (or reverse rows first, then transpose).
    - Rotate by 180 -> reverse rows and reverse columns (or reverse each
      row then reverse the whole matrix top-to-bottom).

    TIME COMPLEXITY  : O(n^2) -> visit every cell a constant number of times
    SPACE COMPLEXITY : O(1) -> in-place transpose and reverse
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // take transpose
        // For clockwise rotation reverse rows

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < matrix.size(); i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

int main() {
    return 0;
}