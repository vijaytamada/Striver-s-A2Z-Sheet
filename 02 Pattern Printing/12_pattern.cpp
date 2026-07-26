/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Number Triangle With a Growing Gap in the Middle
    ============================================================

    INTUITION:
    ----------
    - Each row has 3 parts: ascending numbers (1..num) on the left, a gap of
      spaces in the middle, then descending numbers (num..1) on the right.
    - As rows progress, `num` grows by 1 (more numbers on each side) while
      `spaces` shrinks by 2 (gap gets narrower) — keeping total row width constant.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to n — current row.
    2. Inner loop 1: print numbers 1..num (left side, ascending).
    3. Inner loop 2: print `spaces` gap blocks (middle, empty).
    4. Inner loop 3: print numbers num..1 (right side, descending).
    5. After the row: `num++`, `spaces -= 2`.

    VARIATIONS TO REMEMBER:
    ----------
    - Replace numbers with stars/letters for a similar hollow-middle pyramid.
    - Remove the middle gap loop entirely to get a plain palindrome-style
      number pyramid (1; 1 2 1; 1 2 3 2 1; ...).

    TIME COMPLEXITY  : O(n^2) -> total characters printed across all rows ~ n^2.
    SPACE COMPLEXITY : O(1)  -> only a few counter variables used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        int spaces = 2 * n - 2;
        int num = 1;

        for (int i = 1; i <= n; i++) {
            // Loop fro numbers
            for (int j = 1; j <= num; j++)
                cout << j << " ";

            // Loop for spaces
            for (int j = 1; j <= spaces; j++)
                cout << "  ";

            // Loop fro numbers
            for (int j = num; j >= 1; j--)
                cout << j << " ";

            cout << "\n";

            // Update for next line
            num++;
            spaces -= 2;
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