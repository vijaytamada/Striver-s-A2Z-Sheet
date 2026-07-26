/*
    ============================================================
    TOPIC   : Bit Manipulation - Basic
    PROBLEM : Introduction to Bitwise Operators (AND, OR, XOR, NOT,
              Shifts, Set/Clear/Toggle/Check bit, Power of 2, Set Bits)
    ============================================================

    INTUITION:
    ----------
    - Every integer is stored as a sequence of bits, and each bitwise
      operator manipulates those bits directly, which is much faster
      than equivalent arithmetic operations.
    - This file is a walkthrough/demo of the core bit tricks used
      throughout the rest of the Bit Manipulation topic.

    STEPS:
    ----------
    1. Print binary representation of numbers (showBinary), including
       how negative numbers look in two's complement.
    2. Demonstrate AND (&), OR (|), XOR (^), NOT (~), left shift (<<),
       right shift (>>).
    3. Set the i-th bit: `n | (1 << i)`.
    4. Clear the i-th bit: `n & ~(1 << i)`.
    5. Toggle the i-th bit: `n ^ (1 << i)`.
    6. Check if the i-th bit is set: `(n >> i) & 1`.
    7. Check power of 2: `x && !(x & (x-1))`.
    8. Count set bits with `__builtin_popcount`.

    VARIATIONS TO REMEMBER:
    ----------
    - Each trick shown here has its own dedicated file in this folder
      (ith_bit_set_or_not.cpp, power_of_2.cpp, count_set_bits.cpp, etc.).
    - Two's complement means right-shifting a negative int in C++ is
      implementation-defined/arithmetic shift (sign-extends).

    TIME COMPLEXITY  : O(1) per operation -> all bitwise ops are constant time
    SPACE COMPLEXITY : O(1) -> no extra memory beyond a few ints
    ============================================================
*/

#include <iostream>
using namespace std;

void showBinary(int n) {
    cout << "Binary of " << n << " = ";
    for (int i = 31; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

int main() {
    int a = 29;  // 0001 1101
    int b = 15;  // 0000 1111
    int i = 3;   // Bit position

    cout << "Initial values:\n";
    showBinary(a);
    showBinary(b);
    cout << endl;

    // Bitwise AND
    cout << "a & b = " << (a & b) << endl;
    showBinary(a & b);

    int v = -5;
    cout << "-5 = " << endl;
    showBinary(v);
    
    // Bitwise OR
    cout << "a | b = " << (a | b) << endl;
    showBinary(a | b);

    // Bitwise XOR
    cout << "a ^ b = " << (a ^ b) << endl;
    showBinary(a ^ b);

    // Bitwise NOT
    cout << "~a = " << (~a) << endl;
    showBinary(~a);

    // Left Shift
    cout << "a << 1 = " << (a << 1) << endl;
    showBinary(a << 1);

    // Right Shift
    cout << "a >> 1 = " << (a >> 1) << endl;
    showBinary(a >> 1);

    // Set ith bit
    cout << "Set bit " << i << ": " << (a | (1 << i)) << endl;

    // Clear ith bit
    cout << "Clear bit " << i << ": " << (a & ~(1 << i)) << endl;

    // Toggle ith bit
    cout << "Toggle bit " << i << ": " << (a ^ (1 << i)) << endl;

    // Check if ith bit is set
    cout << "Is bit " << i << " set in a? " << (((a >> i) & 1) ? "Yes" : "No") << endl;

    // Check if a number is power of 2
    int x = 16;
    cout << x << " is power of 2? " << ((x && !(x & (x - 1))) ? "Yes" : "No") << endl;

    // Count set bits
    cout << "Set bits in a: " << __builtin_popcount(a) << endl;

    return 0;
}