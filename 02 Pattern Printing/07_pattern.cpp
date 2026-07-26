/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Solid Pyramid (Centered Triangle of Stars)
    ============================================================

    INTUITION:
    ----------
    - Row i needs leading spaces to push the stars toward the center, and an
      odd number of stars (1, 3, 5, ...) so the shape looks like a pyramid.
    - As stars increase by 2 each row, spaces decrease by 1 each row.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to n — current row.
    2. Inner loop 1: print `space` leading spaces (space starts at n-1).
    3. Inner loop 2: print `star` stars (star starts at 1, jumps by 2 each row).
    4. After the row: `space--`, `star += 2` to set up the next row.

    VARIATIONS TO REMEMBER:
    ----------
    - Reverse the space/star update direction to get the inverted pyramid (pattern 08).
    - Stack this with the inverted version to build a full diamond (pattern 09).

    TIME COMPLEXITY  : O(n^2) -> spaces + stars together sum to ~n^2 across all rows.
    SPACE COMPLEXITY : O(1)  -> only a few counter variables used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        int star = 1;
        int space = n - 1;

        for (int i = 1; i <= n; i++) {
            // Loop for spaces
            for (int j = 1; j <= space; j++)
                cout << " ";

            // Loop for star
            for (int j = 1; j <= star; j++)
                cout << "*";

            cout << endl;

            // Update for next line
            space--;
            star += 2;
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