/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Triangle With Same Letter Repeated per Row (A, BB, CCC, ...)
    ============================================================

    INTUITION:
    ----------
    - Row i has i copies of the SAME letter, and the letter itself advances
      by one row to row (row 1 = A, row 2 = BB, row 3 = CCC, ...).
    - Unlike pattern 14, `ch` is declared OUTSIDE the row loop, so it's not
      reset each row — only incremented once per row, after printing.

    STEPS:
    ----------
    1. `ch = 'A'` set once, before the outer loop starts.
    2. Outer loop `i` from 1 to n — current row.
    3. Inner loop `j` from 1 to i: print `ch` (same letter each time, unchanged).
    4. After the row, newline, then `ch++` to move to the next letter for next row.

    VARIATIONS TO REMEMBER:
    ----------
    - Compare with pattern 04, which does the identical trick but with numbers
      instead of letters.
    - Reset `ch` inside the loop instead to go back to pattern 14's behavior.

    TIME COMPLEXITY  : O(n^2) -> total letters printed ~ n^2/2.
    SPACE COMPLEXITY : O(1)  -> only loop counters and one char variable used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        char ch = 'A';

        for (int i = 1; i <= n; i++) {
            // Loop & print the same letter
            for (int j = 1; j <= i; j++)
                cout << ch;

            cout << '\n';

            // Update for next line
            ch++;
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