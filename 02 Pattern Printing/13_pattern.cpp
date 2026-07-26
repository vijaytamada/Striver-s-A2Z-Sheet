/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Continuous Number Triangle (1; 2 3; 4 5 6; ...)
    ============================================================

    INTUITION:
    ----------
    - Same right-half-pyramid shape as pattern 02, but instead of restarting
      the count each row, keep a single running counter that never resets.
    - Row i still has i numbers, but they continue from where the last row left off.

    STEPS:
    ----------
    1. Keep one counter `count` starting at 1, declared outside the row loop.
    2. Outer loop `i` from 1 to n — current row.
    3. Inner loop `j` from 1 to i: print `count`, then increment it (`count++`).
    4. Newline after each row.

    VARIATIONS TO REMEMBER:
    ----------
    - Reset `count` at the start of each row to get pattern 03 instead.
    - Same running-counter idea works for continuous letters too.

    TIME COMPLEXITY  : O(n^2) -> total numbers printed ~ n^2/2.
    SPACE COMPLEXITY : O(1)  -> only loop counters and one running count used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        // To print continous numbers
        int count = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++)
                cout << count++ << " ";

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