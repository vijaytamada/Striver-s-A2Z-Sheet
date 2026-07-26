/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Right Half Pyramid of Stars
    ============================================================

    INTUITION:
    ----------
    - Row i needs exactly i stars — row 1 has 1 star, row 2 has 2, ..., row n has n.
    - No spaces involved, stars are left-aligned.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to n — represents the current row.
    2. Inner loop `j` from 1 to i — prints one star per iteration (i stars total).
    3. After inner loop, print a newline to move to the next row.

    VARIATIONS TO REMEMBER:
    ----------
    - Flip the outer loop to go from n down to 1 for an inverted right triangle
      (see pattern 05).
    - Replace the star with `j` or `i` to get number triangles (see patterns 03, 04).

    TIME COMPLEXITY  : O(n^2) -> total stars printed = 1+2+...+n ~ n^2/2.
    SPACE COMPLEXITY : O(1)  -> only loop counters used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        for (int i = 1; i <= n; i++) {
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