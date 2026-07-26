/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Binary Number Triangle (Alternating 0s and 1s)
    ============================================================

    INTUITION:
    ----------
    - Each row i has i digits, alternating between 0 and 1.
    - The digit each row *starts* with depends on whether the row number is
      odd or even (`i % 2`), then it flips every step within the row.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to n — current row, also decides the starting digit.
    2. `digit = i % 2` sets the first value printed on this row.
    3. Inner loop `j` from 1 to i: print `digit`, then flip it with `digit = !digit`.

    VARIATIONS TO REMEMBER:
    ----------
    - Flipping the starting formula (e.g. `(i + 1) % 2`) shifts which rows start
      with 0 vs 1.
    - Same "toggle a flag every step" trick is handy anywhere you need alternating output.

    TIME COMPLEXITY  : O(n^2) -> total digits printed ~ n^2/2.
    SPACE COMPLEXITY : O(1)  -> only loop counters and one toggle variable used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        for (int i = 1; i <= n; i++) {
            // Starting digit
            int digit = i % 2;

            for (int j = 1; j <= i; j++) {
                cout << digit << " ";
                // Alternate between 1 & 0 using NOT operator
                digit = !digit;
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
        ob.printTriangle(n);
    }
    return 0;
}