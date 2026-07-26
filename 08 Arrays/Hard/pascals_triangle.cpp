/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : Pascal's Triangle (generate first numRows)
    ============================================================

    INTUITION:
    ----------
    - Every row starts and ends with 1. Every other value in a row is the
      sum of the two values diagonally above it in the previous row
      (currRow[i] = prevRow[i-1] + prevRow[i]).
    - Build row by row, using the previously generated row to compute the
      next one.

    STEPS:
    ----------
    1. For each row number from 1 to numRows:
       - Start currRow as a vector of `rows` ones.
       - If rows > 2, look at the previous row and fill in the middle
         values using currRow[i] = prevRow[i-1] + prevRow[i].
       - Push currRow to the result.
    2. Return all rows.

    VARIATIONS TO REMEMBER:
    ----------
    - "Get row at index rowIndex only" -> can use combinatorics formula
      nCr = nCr-1 * (n-r+1)/r instead of building the whole triangle.
    - "Get single element at (row, col)" -> direct combinatorics formula
      C(row, col) is O(col) instead of building everything.

    TIME COMPLEXITY  : O(numRows^2) -> total elements across all rows
    SPACE COMPLEXITY : O(numRows^2) -> output stores every element (unavoidable for full triangle)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int rows = 1; rows <= numRows; rows++) {
            vector<int> currRow(rows, 1);

            if (rows > 2) {
                vector<int> prevRow = res.back();
                for (int i = 1; i < currRow.size() - 1; i++) {
                    currRow[i] = prevRow[i - 1] + prevRow[i];
                }
            }

            res.push_back(currRow);
        }

        return res;
    }
};

int main() {
    return 0;
}