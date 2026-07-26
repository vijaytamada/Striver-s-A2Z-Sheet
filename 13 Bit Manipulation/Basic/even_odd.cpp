/*
    ============================================================
    TOPIC   : Bit Manipulation - Basic
    PROBLEM : Check if a Number is Even or Odd Using Bitwise AND
    ============================================================

    INTUITION:
    ----------
    - The least significant bit of a number's binary form is 1 for odd
      numbers and 0 for even numbers, so `n & 1` directly tells you the
      parity without using the `%` operator.

    STEPS:
    ----------
    1. Compute `n & 1`.
    2. If the result is 1, n is odd; if 0, n is even.

    VARIATIONS TO REMEMBER:
    ----------
    - `n % 2` works the same way but bitwise AND is typically faster.
    - Checking power of 2 (power_of_2.cpp) uses a related trick:
      `n & (n-1) == 0`.

    TIME COMPLEXITY  : O(1) -> single bitwise operation
    SPACE COMPLEXITY : O(1) -> no extra memory
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if a number is odd
    bool isOdd(int n) {
        return (n & 1 != 0);  // Return true if the number is odd, else false
    }
};

int main() {
    Solution sol;
    int num = 7;

    if (sol.isOdd(num)) {
        cout << num << " is odd." << endl;
    } else {
        cout << num << " is not odd." << endl;
    }

    return 0;
}