/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Star Pattern That Grows Then Shrinks (No Leading Spaces)
    ============================================================

    INTUITION:
    ----------
    - Like a diamond's silhouette but left-aligned (no spaces) — the star count
      per row goes 1,2,...,n,...,2,1 across 2n-1 rows.
    - Track whether we're before or after the middle row (`i < n`) to decide
      whether to grow or shrink the star count.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to 2n-1 — total rows.
    2. Inner loop: print `stars` stars for the current row.
    3. If `i < n`, increment stars for the next row; otherwise decrement.

    VARIATIONS TO REMEMBER:
    ----------
    - Add leading spaces that shrink-then-grow the same way to turn this into
      a centered diamond outline instead of a left-aligned shape.
    - Swap stars for letters/numbers for alphabet or number versions.

    TIME COMPLEXITY  : O(n^2) -> total stars printed ~ n^2.
    SPACE COMPLEXITY : O(1)  -> only a couple of counter variables used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        int stars = 1;
        int lines = 2 * n - 1;

        for (int i = 1; i <= lines; i++) {
            // Loop for stars
            for (int j = 1; j <= stars; j++)
                cout << "* ";

            cout << '\n';

            // update for next line
            if (i < n)
                stars++;
            else
                stars--;
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