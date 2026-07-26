/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Right Half Pyramid with Row Number Repeated
    ============================================================

    INTUITION:
    ----------
    - Same shape as pattern 02/03, but every row just repeats its own row
      number i times — row i prints "i i i ... " (i times).

    STEPS:
    ----------
    1. Outer loop `i` from 1 to n — current row number (also the value to print).
    2. Inner loop `j` from 1 to i — just controls how many times to print `i`,
       `j` itself is not printed.
    3. Newline after each row.

    VARIATIONS TO REMEMBER:
    ----------
    - Compare with pattern 03, where `j` (changing value) is printed instead of `i`.
    - Useful base for patterns that print "row-constant" values, like the
      character-repeat pattern (pattern 16).

    TIME COMPLEXITY  : O(n^2) -> total numbers printed ~ n^2/2.
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
                cout << i << " ";

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