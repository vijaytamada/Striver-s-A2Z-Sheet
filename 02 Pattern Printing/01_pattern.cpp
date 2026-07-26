/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Solid Square of Stars (n x n)
    ============================================================

    INTUITION:
    ----------
    - Every row is identical: print n stars, n times (n rows).
    - Simplest possible pattern — no spaces, no changing counts.

    STEPS:
    ----------
    1. Outer loop runs n times — one for each row.
    2. Inner loop runs n times — prints "* " for each column in that row.
    3. After the inner loop finishes, move to a new line.

    VARIATIONS TO REMEMBER:
    ----------
    - Change the inner loop's fixed count to make a rectangle instead of a square.
    - Make it hollow by only printing '*' on the border rows/columns (see hollow
      square pattern later in this folder).

    TIME COMPLEXITY  : O(n^2) -> nested loop each running n times.
    SPACE COMPLEXITY : O(1)  -> no extra space used besides loop counters.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printSquare(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "* ";
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