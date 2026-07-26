/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Right Half Pyramid of Numbers (1 to i per row)
    ============================================================

    INTUITION:
    ----------
    - Same shape as the star pyramid, but each row prints the numbers 1..i
      instead of stars.
    - The inner loop variable `j` itself is the value to print.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to n — current row number.
    2. Inner loop `j` from 1 to i — print `j` (so row i prints "1 2 3 ... i").
    3. Newline after each row.

    VARIATIONS TO REMEMBER:
    ----------
    - Print `i` instead of `j` to make every row show the row number repeated
      (see pattern 04).
    - Reverse the inner loop (`j` from i to 1) to print numbers in descending order.

    TIME COMPLEXITY  : O(n^2) -> total numbers printed ~ n^2/2.
    SPACE COMPLEXITY : O(1)  -> only loop counters used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        for (int i = 1; i <= n; i++) {
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