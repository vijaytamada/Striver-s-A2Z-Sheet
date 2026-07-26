/*
    ============================================================
    TOPIC   : Bit Manipulation - Basic
    PROBLEM : Divide Two Integers Without Using Division/Multiplication
    ============================================================

    INTUITION:
    ----------
    - Division is repeated subtraction, but subtracting the divisor one
      at a time is too slow (O(dividend/divisor)). Instead, subtract the
      LARGEST possible multiple of the divisor (a power-of-2 multiple)
      each round, which is what left-shifting simulates.
    - Left-shifting a number doubles it, so doubling the divisor via
      shifts until it's about to exceed the remaining dividend finds the
      biggest chunk to subtract in one go — this mimics binary search.

    STEPS:
    ----------
    1. Handle overflow edge case: INT_MIN / -1 doesn't fit in an int.
    2. Determine the sign of the result using XOR of the operand signs.
    3. Work with absolute values (as long long to avoid overflow).
    4. While remaining dividend >= divisor: keep doubling the divisor
       (and a matching "multiple" counter) via left shift as long as
       doubling doesn't exceed the remaining dividend.
    5. Subtract that doubled chunk from the dividend, add the multiple
       to the running result, and repeat.
    6. Apply the sign to the final result.

    VARIATIONS TO REMEMBER:
    ----------
    - The brute force O(N) version (Solution1) just subtracts the
      divisor one at a time — correct but times out for large inputs.
    - Similar shift-and-subtract idea appears in binary long division
      and in computing GCD-like problems without built-in operators.

    TIME COMPLEXITY  : O((log N)^2) -> outer loop runs O(log N) times, inner doubling also O(log N)
    SPACE COMPLEXITY : O(1) -> only a few long long variables used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach - O(N) time complexity - TLE
class Solution1 {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

        long long dd = abs((long long)dividend);
        long long ds = abs((long long)divisor);

        long long res = 0;

        while (dd >= ds) {
            dd -= ds;
            res++;
        }

        return sign * res;
    }
};

// Optimized Approach - O(log N) time complexity
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

        long long dd = abs((long long)dividend);
        long long ds = abs((long long)divisor);
        long long res = 0;

        while (dd >= ds) {
            long long temp = ds, multiple = 1;
            while (dd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dd -= temp;
            res += multiple;
        }

        return sign * res;
    }
};

int main()
{
    

    return 0;
}