/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Inverted Right Half Pyramid of Stars
    ============================================================

    INTUITION:
    ----------
    - Mirror image of pattern 02 (top-to-bottom) — first row has n stars,
      last row has 1 star.
    - Just run the outer loop backwards (n down to 1) instead of forwards.

    STEPS:
    ----------
    1. Outer loop `i` from n down to 1 — current row's star count.
    2. Inner loop `j` from 1 to i — prints i stars for that row.
    3. Newline after each row.

    VARIATIONS TO REMEMBER:
    ----------
    - Combine this with pattern 02 (pyramid then inverted pyramid stacked)
      to make a full diamond (see pattern 09).
    - Same trick (flip outer loop direction) turns pattern 03 into pattern 06.

    TIME COMPLEXITY  : O(n^2) -> total stars printed ~ n^2/2.
    SPACE COMPLEXITY : O(1)  -> only loop counters used.
    ============================================================
*/
// Enter the number of rows: 5
// * * * * *
// * * * *
// * * *
// * *
// *

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= i; j++)
                cout << "* ";

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
        ob.printTriangle(n);
    }
    return 0;
}
