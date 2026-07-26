/*
    ============================================================
    TOPIC   : Bit Manipulation - Basic
    PROBLEM : Check if a Number is a Power of 2
    ============================================================

    INTUITION:
    ----------
    - A power of 2 has exactly one bit set in binary (e.g. 8 = 1000).
      Subtracting 1 from it flips that bit to 0 and all lower bits to 1
      (e.g. 7 = 0111). ANDing the two together always gives 0 only when
      there was exactly one set bit to begin with.

    STEPS:
    ----------
    1. Reject non-positive numbers (n must be > 0).
    2. Compute `n & (n - 1)`.
    3. If the result is 0, n is a power of 2.

    VARIATIONS TO REMEMBER:
    ----------
    - The same `n & (n-1)` trick clears the lowest set bit — used in
      Brian Kernighan's set-bit-counting algorithm.
    - Finding the next power of 2 >= n uses bit-shifting tricks too.

    TIME COMPLEXITY  : O(1) -> single AND operation
    SPACE COMPLEXITY : O(1) -> no extra memory
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ((n & (n - 1)) == 0);
    }
};

int main() {
    return 0;
}