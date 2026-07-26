/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Butterfly Pattern (Two Triangles Meeting in the Middle)
    ============================================================

    INTUITION:
    ----------
    - Picture two right triangles facing each other, left and right, with a
      gap of spaces between them that narrows toward the middle row and widens
      again after — like a bowtie/butterfly shape.
    - Top half: stars shrink and the middle gap grows as rows progress toward n.
      Bottom half: the reverse happens (stars grow back, gap shrinks).

    STEPS:
    ----------
    1. Outer loop `i` from 1 to 2n — total rows (n for upper wing, n for lower wing).
    2. Print `stars` stars (left wing), then `spaces` gap blocks, then `stars`
       stars again (right wing).
    3. If `i < n`: shrink stars, grow the gap (upper wing narrowing at waist).
       If `i > n`: grow stars back, shrink the gap (lower wing widening out).

    VARIATIONS TO REMEMBER:
    ----------
    - Add leading/trailing space-triangles around this to build a bordered
      hourglass or bowtie shape.
    - Reversing which half grows/shrinks flips it into an hourglass instead
      of a butterfly (see pattern 20 for a related converging shape).

    TIME COMPLEXITY  : O(n^2) -> total characters printed across all rows ~ n^2.
    SPACE COMPLEXITY : O(1)  -> only a couple of counter variables used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        int stars = n;
        int spaces = 0;

        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 1; j <= stars; j++)
                cout << "*";

            for (int j = 1; j <= spaces; j++)
                cout << "  ";

            for (int j = 1; j <= stars; j++)
                cout << "*";

            cout << "\n";

            if (i < n) {
                stars--;
                spaces++;
            } else if (i > n) {
                spaces--;
                stars++;
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
