/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Right Half Pyramid of Letters (A, AB, ABC, ...)
    ============================================================

    INTUITION:
    ----------
    - Same shape as the numeric right-half pyramid (pattern 02/03), but prints
      letters starting from 'A' instead.
    - Each row restarts the letter from 'A' and increments it as it prints.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to n — current row.
    2. Reset `ch = 'A'` at the start of every row.
    3. Inner loop `j` from 1 to i: print `ch`, then `ch++` (moves to next letter).
    4. Newline after each row.

    VARIATIONS TO REMEMBER:
    ----------
    - Flip outer loop direction (n down to 1) to get the inverted version (pattern 15).
    - Don't reset `ch` each row (keep it outside the outer loop) for a
      continuous-letter version, similar to pattern 13's continuous numbers.

    TIME COMPLEXITY  : O(n^2) -> total letters printed ~ n^2/2.
    SPACE COMPLEXITY : O(1)  -> only loop counters and one char variable used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        for (int i = 1; i <= n; i++) {
            char ch = 'A';

            // Loop from A
            for (int j = 1; j <= i; j++)
                cout << ch++;

            cout << '\n';
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