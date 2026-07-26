/*
    ============================================================
    TOPIC   : Recursion - Basic
    PROBLEM : Count Good Numbers (digit string of length n where even
              indices hold prime digits 2,3,5,7 and odd indices hold
              even digits 0,2,4,6,8)
    ============================================================

    INTUITION:
    ----------
    - Every even index independently has 4 valid digit choices and every
      odd index independently has 5 valid digit choices, so the total
      count is just 4^(#even positions) * 5^(#odd positions) mod 1e9+7.
    - Since n can be huge, raw multiplication is too slow — use fast
      exponentiation (binary exponentiation) to compute powers in
      O(log n) instead of O(n).

    STEPS:
    ----------
    1. Split n into count of even-index slots and odd-index slots.
    2. Compute 5^(oddCount) mod m and 4^(evenCount) mod m using fast
       power (square-and-multiply, halving the exponent each step).
    3. Multiply the two results together mod m.
    4. Return the final answer.

    VARIATIONS TO REMEMBER:
    ----------
    - Classic "modular exponentiation" pattern reused in many problems
      (e.g. computing a^b % m for huge b).
    - The recursive modPow2 here is written but not fully wired to use
      itself for both halves — the iterative modPow is what's actually used.

    TIME COMPLEXITY  : O(log n) -> binary exponentiation halves exponent each call
    SPACE COMPLEXITY : O(1) -> iterative version uses no extra stack/structure
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mod;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    // Recursive version
    long long modPow2(long long base, long long exp) {
        if (exp == 0)
            return 1;  // Base case: anything to power 0 is 1

        long long half = modPow(base, exp / 2);
        long long result = (half * half) % mod;

        if (exp % 2 == 1)  // If exponent is odd, multiply once more by base
            result = (result * base) % mod;

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = n / 2;
        long long oddPos = n / 2 + n % 2;
        this->mod = 1e9 + 7;

        // odd positions: digits 0,2,4,6,8 (5 choices)
        // even positions: digits 2,3,5,7 (4 choices)
        long long goodNum = (modPow(5, oddPos) * modPow(4, evenPos)) % mod;
        return static_cast<int>(goodNum);
    }
};

int main() {
    return 0;
}