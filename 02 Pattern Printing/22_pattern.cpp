/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Concentric Square of Numbers (Number Layers/Boundary Pattern)
    ============================================================

    INTUITION:
    ----------
    - Picture n nested square "rings", each labeled with a number: the outermost
      ring is n, and it counts down to 1 at the very center.
    - Each row is built in 3 parts: numbers counting down into the middle
      (left side), the row's minimum value repeated across the middle, then
      numbers counting back up (right side) — like peeling layers of an onion.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to 2n-1 — total rows.
    2. `outerLimit` (grows toward the middle, then shrinks) controls how many
       "descending layer" numbers to print on the left before the flat middle.
    3. Print `outerLimit` descending numbers, then `innerLimit` copies of the
       current smallest number (the flat middle), then `outerLimit` ascending
       numbers back up (mirrors the left side).
    4. Before/at the middle row, `outerLimit++` and `innerLimit -= 2`; after
       the middle, reverse those updates.

    VARIATIONS TO REMEMBER:
    ----------
    - Replace numbers with the same repeated symbol to get concentric square
      "rings" made of characters instead.
    - This is conceptually similar to peeling matrix layers (common in 2D
      array/matrix traversal problems).

    TIME COMPLEXITY  : O(n^2) -> visits every cell in the (2n-1) x (2n-1) grid.
    SPACE COMPLEXITY : O(1)  -> only a few counter variables used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printSquare(int n) {
        // Repetetive numbers
        int innerLimit = 2 * n - 1;

        // Changing changing
        int outerLimit = 0;

        for (int i = 1; i <= 2 * n - 1; i++) {
            int num = n;
            for (int j = 1; j <= outerLimit; j++)
                cout << num-- << " ";

            for (int j = 1; j <= innerLimit; j++)
                cout << num << " ";

            for (int j = 1; j <= outerLimit; j++)
                cout << ++num << " ";

            if (i < n) {
                outerLimit++;
                innerLimit -= 2;
            } else {
                outerLimit--;
                innerLimit += 2;
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