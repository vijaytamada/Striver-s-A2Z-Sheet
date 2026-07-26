/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Hollow Square (Border Only)
    ============================================================

    INTUITION:
    ----------
    - The first and last rows are fully solid (the top/bottom border).
    - Every other row only needs stars at the very first and last column
      (the left/right border); everything in between is blank space.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to n — current row.
    2. If it's the first or last row (`i == 1 || i == n`), print n stars
       (a solid border row).
    3. Otherwise, loop through columns `j`: print '*' only if `j` is the
       first or last column, else print a space.

    VARIATIONS TO REMEMBER:
    ----------
    - Combine with the solid square (pattern 01) as a mental "before/after"
      comparison of solid vs hollow shapes.
    - Extend the same "border only" idea to hollow diamonds/rhombuses.

    TIME COMPLEXITY  : O(n^2) -> still visits every cell in the n x n grid.
    SPACE COMPLEXITY : O(1)  -> only loop counters used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printSquare(int n) {
        for (int i = 1; i <= n; i++) {
            if (i == 1 || i == n)
                for (int j = 1; j <= n; j++)
                    cout << "*";
            else {
                for (int j = 1; j <= n; j++) {
                    if (j == 1 || j == n)
                        cout << "*";
                    else
                        cout << " ";
                }
            }

            cout << "\n";
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printSquare(n);
    }
    return 0;
}