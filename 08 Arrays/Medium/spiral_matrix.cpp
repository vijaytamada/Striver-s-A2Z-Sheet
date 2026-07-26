/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Spiral Matrix Traversal
    ============================================================

    INTUITION:
    ----------
    - Maintain 4 boundaries: top, down (bottom), left, right.
    - Traverse the top row left-to-right, then the right column
      top-to-bottom, then the bottom row right-to-left, then the left
      column bottom-to-top - and after each side is done, shrink that
      boundary inward.
    - Keep cycling through these 4 directions until the boundaries cross.

    STEPS:
    ----------
    1. Init top=left=0, down=rows-1, right=cols-1, dir=0.
    2. While top <= down && left <= right:
       - dir 0: traverse row `top` left to right, then top++.
       - dir 1: traverse col `right` top to bottom, then right--.
       - dir 2: traverse row `down` right to left, then down--.
       - dir 3: traverse col `left` bottom to top, then left++.
       - dir = (dir + 1) % 4.
    3. Return the collected traversal.

    VARIATIONS TO REMEMBER:
    ----------
    - "Spiral Matrix II" - generate an NxN matrix filled 1..N^2 in spiral
      order (same boundary-shrinking idea, just filling instead of reading).

    TIME COMPLEXITY  : O(m*n) -> every cell visited exactly once
    SPACE COMPLEXITY : O(1) extra (excluding the output array)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir = 0;
        int top, down, right, left;
        vector<int> traversal;

        top = left = 0;
        down = matrix.size() - 1;
        right = matrix[0].size() - 1;

        while (top <= down && left <= right) {
            if (dir == 0) {
                for (int i = left; i <= right; ++i)
                    traversal.push_back(matrix[top][i]);

                top++;
            } else if (dir == 1) {
                for (int i = top; i <= down; ++i)
                    traversal.push_back(matrix[i][right]);

                right--;
            } else if (dir == 2) {
                for (int i = right; i >= left; i--)
                    traversal.push_back(matrix[down][i]);

                down--;
            } else {
                for (int i = down; i >= top; i--)
                    traversal.push_back(matrix[i][left]);

                left++;
            }

            dir = (dir + 1) % 4;
        }

        return traversal;
    }
};

int main() {
    return 0;
}