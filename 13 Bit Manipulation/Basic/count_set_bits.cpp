/*
    ============================================================
    TOPIC   : Bit Manipulation - Basic
    PROBLEM : Count Set Bits (number of 1s in binary representation)
    ============================================================

    INTUITION:
    ----------
    - Checking `n & 1` tells you if the least significant bit is 1, and
      right-shifting `n` moves the next bit into that position, so
      looping this way inspects every bit exactly once.

    STEPS:
    ----------
    1. Initialize a counter to 0.
    2. While n > 0: add (n & 1) to the counter (adds 1 if last bit set).
    3. Right shift n by 1 to drop the bit just checked.
    4. Return the counter once n becomes 0.

    VARIATIONS TO REMEMBER:
    ----------
    - Brian Kernighan's trick: `n & (n-1)` clears the lowest set bit,
      loop until n is 0 — runs in O(number of set bits) instead of O(bits).
    - Built-in `__builtin_popcount(n)` does this in one call (used here
      for comparison).

    TIME COMPLEXITY  : O(log n) -> processes one bit per iteration (32 bits max for int)
    SPACE COMPLEXITY : O(1) -> single counter variable
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count the number of set bits (1s) in the binary representation of n
    int countSetBits(int n) {
        int count = 0;  // Variable to store the count of set bits

        // Step 1: Count the number of set bits using bitwise operations
        while (n > 0) {
            count += (n & 1);  // Check if the least significant bit is set (1)
            n >>= 1;           // Right shift n by 1 to process the next bit
        }

        // Step 2: Return the count of set bits
        return count;
    }
};

// Main function to test the solution
int main() {
    int n = 29;  // Example input for n (binary: 11101)

    Solution sol;
    int result = sol.countSetBits(n);

    cout << "The number of set bits is: " << result << endl;

    // In-built function
    cout << "Using in build fn : " << __builtin_popcount(n);

    return 0;
}