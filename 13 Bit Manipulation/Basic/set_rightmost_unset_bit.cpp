/*
    ============================================================
    TOPIC   : Bit Manipulation - Basic
    PROBLEM : Set the Rightmost Unset Bit (turn the lowest 0 bit into a 1)
    ============================================================

    INTUITION:
    ----------
    - Adding 1 to n causes a carry that ripples through the trailing 1s
      and flips the first 0 bit it hits to 1 (while turning those
      trailing 1s to 0s in n+1). ORing n with (n+1) keeps all of n's
      original 1 bits and adds that newly-flipped bit, effectively
      setting just the rightmost unset bit.

    STEPS:
    ----------
    1. Compute n + 1 (this flips the rightmost 0 to 1 and clears bits
       below it).
    2. OR it with the original n to restore n's bits that n+1 cleared.
    3. Return the result.

    VARIATIONS TO REMEMBER:
    ----------
    - Clearing the rightmost set bit uses `n & (n-1)` (opposite idea).
    - Isolating the rightmost set bit uses `n & (-n)`.

    TIME COMPLEXITY  : O(1) -> constant number of bitwise operations
    SPACE COMPLEXITY : O(1) -> no extra memory
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Function to set the rightmost unset bit (0 -> 1)
int setRightmostUnsetBit(int n) {
    // Use bitwise OR with n+1 to set rightmost 0
    return n | (n + 1);
}

int main() {
    // Sample input
    int n = 10;  // binary: 1010

    // Call function
    int result = setRightmostUnsetBit(n);

    // Print output
    cout << "Number after setting rightmost unset bit: " << result << endl;  // Output: 11

    return 0;
}