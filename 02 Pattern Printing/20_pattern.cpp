/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Converging-Diverging Star Pattern (X / Hourglass-like Shape)
    ============================================================

    INTUITION:
    ----------
    - Two columns of stars (left and right) with a gap between them that
      narrows as rows approach the middle row, closing completely at the
      middle (forming one solid line), then reopening below — like two
      diagonal lines crossing at the center (an X shape).
    - Track whether we're above or below the middle row (`i < n`) to decide
      whether the gap should shrink or grow.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to 2n-1 — total rows.
    2. Print `stars` stars (left), `spaces` gap, `stars` stars (right).
    3. If `i < n`: gap shrinks by 2, stars grow by 1 (converging toward center).
       Otherwise: gap grows by 2, stars shrink by 1 (diverging after center).

    VARIATIONS TO REMEMBER:
    ----------
    - Very similar to the butterfly (pattern 19), but this one closes into a
      single solid row in the middle instead of staying open.
    - Swapping which half grows/shrinks changes it from an X shape into a
      diamond outline.

    TIME COMPLEXITY  : O(n^2) -> total characters printed across all rows ~ n^2.
    SPACE COMPLEXITY : O(1)  -> only a couple of counter variables used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        int stars = 1;
        int spaces = 2 * n - 2;

        for (int i = 1; i <= 2 * n - 1; i++) {
            for (int j = 1; j <= stars; j++)
                cout << "*";

            for (int j = 1; j <= spaces; j++)
                cout << " ";

            for (int j = 1; j <= stars; j++)
                cout << "*";

            cout << "\n";

            if (i < n) {
                spaces -= 2;
                stars++;
            } else {
                spaces += 2;
                stars--;
            }
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