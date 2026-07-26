/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Inverted Right Half Pyramid of Numbers (1 to i per row)
    ============================================================

    INTUITION:
    ----------
    - Same as pattern 05, but prints numbers 1..i instead of stars.
    - First row prints "1 2 ... n", each following row has one fewer number.

    STEPS:
    ----------
    1. Outer loop `i` from n down to 1 — how many numbers this row has.
    2. Inner loop `j` from 1 to i — print `j` (row prints "1 2 ... i").
    3. Newline after each row.

    VARIATIONS TO REMEMBER:
    ----------
    - This is pattern 03 with the outer loop direction flipped.
    - Stacking pattern 03 then this one (skipping the duplicate middle row)
      gives a number-based diamond.

    TIME COMPLEXITY  : O(n^2) -> total numbers printed ~ n^2/2.
    SPACE COMPLEXITY : O(1)  -> only loop counters used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= i; j++)
                cout << j << " ";

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