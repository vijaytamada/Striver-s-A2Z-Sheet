/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Full Diamond of Stars
    ============================================================

    INTUITION:
    ----------
    - A diamond is just a pyramid (pattern 07) on top, followed immediately by
      an inverted pyramid (pattern 08) on the bottom — 2n rows total.
    - Track whether we're still in the "growing" (upper) half or the "shrinking"
      (lower) half using the row index vs n.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to 2n — total rows (n for top half, n for bottom half).
    2. Inner loop 1: print `spaces` leading spaces.
    3. Inner loop 2: print `stars` stars.
    4. If `i < n`, grow (stars++, spaces--); if `i > n`, shrink (stars--, spaces++).

    VARIATIONS TO REMEMBER:
    ----------
    - This is literally pattern 07 + pattern 08 stitched together.
    - Swap stars for numbers/letters to get numeric or alphabet diamonds.

    TIME COMPLEXITY  : O(n^2) -> total characters printed across all rows ~ n^2.
    SPACE COMPLEXITY : O(1)  -> only a few counter variables used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printDiamond(int n) {
        int stars = 1;
        int spaces = n - 1;
        int lines = 2 * n;

        for (int i = 1; i <= lines; i++) {
            // Loop for spaces
            for (int j = 1; j <= spaces; j++)
                cout << " ";

            // Loop for stars
            for (int j = 1; j <= stars; j++)
                cout << "* ";

            cout << "\n";

            // Update accordingly for next line
            if (i < n) {
                stars++;
                spaces--;
            } else if (i > n) {
                stars--;
                spaces++;
            }
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
        ob.printDiamond(n);
    }
    return 0;
}