/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Inverted Right Half Pyramid of Letters
    ============================================================

    INTUITION:
    ----------
    - Mirror image of pattern 14 — first row has n letters (A to the nth
      letter), last row has just "A".
    - Outer loop runs backwards (n down to 1), letters still reset to 'A' each row.

    STEPS:
    ----------
    1. Outer loop `i` from n down to 1 — current row's letter count.
    2. Reset `ch = 'A'` at the start of every row.
    3. Inner loop `j` from 1 to i: print `ch`, then `ch++`.
    4. Newline after each row.

    VARIATIONS TO REMEMBER:
    ----------
    - This is pattern 14 with the outer loop direction flipped, same trick as
      pattern 02 -> pattern 05.
    - Stack pattern 14 then this one (minus the duplicate middle row) for a
      letter diamond.

    TIME COMPLEXITY  : O(n^2) -> total letters printed ~ n^2/2.
    SPACE COMPLEXITY : O(1)  -> only loop counters and one char variable used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        for (int i = n; i >= 1; i--) {
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