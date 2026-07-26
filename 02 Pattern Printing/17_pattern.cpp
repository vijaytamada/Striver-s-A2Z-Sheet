/*
    ============================================================
    TOPIC   : Pattern Printing
    PROBLEM : Centered Pyramid of Letters (Palindrome Style: A, ABA, ABCBA, ...)
    ============================================================

    INTUITION:
    ----------
    - Same centering idea as the star pyramid (pattern 07): leading spaces
      shrink each row so the shape stays centered.
    - Each row prints letters going up from 'A' to the row's peak letter, then
      immediately comes back down (mirrored), forming a palindrome per row.

    STEPS:
    ----------
    1. Outer loop `i` from 1 to n — current row.
    2. Print `spaces` leading spaces (shrinks by 1 each row).
    3. Forward half: print letters 'A' up to the row's peak, i letters, incrementing `ch`.
    4. Step back 2 letters (`ch -= 2`) then print the reverse half (i-1 letters),
       decrementing `ch` each time — this mirrors the forward half.
    5. Newline, then `spaces--` for the next row.

    VARIATIONS TO REMEMBER:
    ----------
    - Same forward-then-mirror trick works with numbers for a palindrome
      number pyramid (1, 121, 12321, ...).
    - Removing the leading spaces gives a left-aligned version of this pattern.

    TIME COMPLEXITY  : O(n^2) -> total characters printed across all rows ~ n^2.
    SPACE COMPLEXITY : O(1)  -> only a few counter/char variables used.
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printTriangle(int n) {
        int spaces = n - 1;

        for (int i = 1; i <= n; i++) {
            // Loop for spaces
            for (int j = 1; j <= spaces; j++)
                cout << " ";

            char ch = 'A';

            // Loop for forward half
            for (int j = 1; j <= i; j++)
                cout << ch++;

            ch -= 2;

            // Loop for reverse half
            for (int j = 1; j <= i - 1; j++)
                cout << ch--;

            cout << "\n";

            // Update for next line
            spaces--;
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