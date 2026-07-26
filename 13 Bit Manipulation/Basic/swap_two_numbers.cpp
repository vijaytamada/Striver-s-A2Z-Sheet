/*
    ============================================================
    TOPIC   : Bit Manipulation - Basic
    PROBLEM : Swap Two Numbers Without a Temp Variable (XOR swap)
    ============================================================

    INTUITION:
    ----------
    - XOR is its own inverse: `x ^ y ^ y = x`. By chaining three XOR
      operations between a and b, each variable ends up holding the
      other's original value without ever needing a third temp variable.

    STEPS:
    ----------
    1. a = a ^ b  (a now holds the XOR of both original values).
    2. b = a ^ b  (this cancels out b, leaving original a in b).
    3. a = a ^ b  (this cancels out original a, leaving original b in a).

    VARIATIONS TO REMEMBER:
    ----------
    - The classic temp-variable swap (`temp = a; a = b; b = temp;`) is
      simpler and safer — XOR swap breaks if a and b are the same memory
      location (it zeroes the value out).
    - Swap using arithmetic (a = a+b; b = a-b; a = a-b) has similar
      caveats around overflow.

    TIME COMPLEXITY  : O(1) -> three XOR operations
    SPACE COMPLEXITY : O(1) -> no extra variable needed
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Function to swap using XOR bit manipulation
void swapXOR(int &a, int &b) {
    // Step 1: XOR a and b, store in a
    a = a ^ b;

    // Step 2: XOR new a with b, result is original a → store in b
    b = a ^ b;

    // Step 3: XOR new a with new b, result is original b → store in a
    a = a ^ b;
}

int main() {
    int a = 5, b = 10;

    // Call the swap function
    swapXOR(a, b);

    // Print the result after swapping
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}