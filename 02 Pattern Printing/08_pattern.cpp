/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Inverted Solid Pyramid (Centered, Upside Down)
    ============================================================

    INTUITION:
    ----------
    - Mirror of pattern 07: first row is widest (2n-1 stars, 0 spaces), and it
      narrows down to a single star on the last row.
    - Spaces increase by 1 each row while stars shrink by 2.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to n — current row.
    2. Inner loop 1: print `spaces` leading spaces (starts at 0).
    3. Inner loop 2: print `stars` stars (starts at 2n-1).
    4. After the row: `spaces++`, `stars -= 2` to shrink for the next row.

    VARIATIONS TO REMEMBER:
    ----------
    - This is pattern 07 with the space/star update directions swapped.
    - Combine with pattern 07 (pyramid on top, this on the bottom) to form a
      full diamond, similar to pattern 09.

    TIME COMPLEXITY  : O(n^2) -> spaces + stars together sum to ~n^2 across all rows.
    SPACE COMPLEXITY : O(1)  -> only a few counter variables used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        int spaces = 0;
        int stars = 2 * n - 1;

        for (int i = 1; i <= n; i++) {
            // Loop for Spaces
            for (int j = 1; j <= spaces; j++)
                cout << " ";

            // Loop for Stars
            for (int j = 1; j <= stars; j++)
                cout << "*";

            cout << "\n";

            // Update for next line
            spaces++;
            stars -= 2;
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
        ob.printTriangle(n);
    }
    return 0;
}