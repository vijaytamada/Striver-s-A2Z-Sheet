/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Right Half Pyramid of Descending Letters (Same Top Letter Every Row)
    ============================================================

    INTUITION:
    ----------
    - Right-half-pyramid shape (row i has i letters), but every row starts
      from the SAME top letter (`'A' + n - 1`, i.e. the nth letter) and counts
      down from there.
    - Because `letter` is reset inside the outer loop, every row looks like a
      descending run ending closer and closer to that fixed top letter.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to n — current row.
    2. Reset `letter = 'A' + (n - 1)` at the start of every row (always the same value).
    3. Inner loop `j` from 1 to i: print `letter`, then decrement it.
    4. Newline after each row.

    VARIATIONS TO REMEMBER:
    ----------
    - If instead `letter` was NOT reset each row (kept outside the loop),
      you'd get a continuously descending letter run across the whole triangle.
    - Compare with pattern 14, which counts UP from 'A' and resets each row too.

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
            char letter = 'A' + (n - 1);

            for (int j = 1; j <= i; j++) {
                cout << letter << " ";
                letter--;
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