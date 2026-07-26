/*
    ============================================================
    TOPIC   : Bit Manipulation - Basic
    PROBLEM : Check if the i-th Bit of a Number is Set
    ============================================================

    INTUITION:
    ----------
    - `1 << i` creates a number with only the i-th bit set (a mask).
      ANDing n with this mask isolates that single bit — if the result
      is non-zero, the i-th bit of n must have been 1.

    STEPS:
    ----------
    1. Build the mask `1 << i`.
    2. Compute `n & mask`.
    3. If the result is non-zero, the i-th bit is set; otherwise it isn't.

    VARIATIONS TO REMEMBER:
    ----------
    - Setting/clearing/toggling the i-th bit uses the same mask idea
      with OR, AND-NOT, and XOR respectively (see intro.cpp).
    - Counting all set bits (count_set_bits.cpp) checks every bit this way in a loop.

    TIME COMPLEXITY  : O(1) -> single shift and AND operation
    SPACE COMPLEXITY : O(1) -> no extra memory
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if the i-th bit of number n is set (1)
    bool checkIthBit(int n, int i) {
        // Check if the i-th bit is set using bitwise AND operation
        return (n & (1 << i)) != 0;  // If the i-th bit is 1, the result will be non-zero
    }
};

int main() {
    Solution sol;
    int num = 5;       // Binary: 101
    int bitIndex = 2;  // Check the 2nd bit (0-based index)

    if (sol.checkIthBit(num, bitIndex)) {
        cout << "The " << bitIndex << "-th bit of " << num << " is set (1)." << endl;
    } else {
        cout << "The " << bitIndex << "-th bit of " << num << " is not set (0)." << endl;
    }

    return 0;
}