/*
    ============================================================
    TOPIC   : Recursion - Basic
    PROBLEM : Pow(x, n) - compute x raised to the power n
    ============================================================

    INTUITION:
    ----------
    - Naively multiplying x by itself n times is O(n); instead, notice
      that x^n = (x^(n/2))^2, halving the problem size each recursive
      call gives O(log n).
    - Negative exponents are handled by inverting x (1/x) and flipping
      the sign of n to a positive value first.

    STEPS:
    ----------
    1. (Brute) Recurse down by 1 each call: x^n = x * x^(n-1), base
       case x^0 = 1. This is O(n).
    2. (Optimal) Recurse by halving: compute half = x^(n/2) once, then
       square it. If n is odd, multiply one extra x in.
    3. Before recursing, if n is negative, set x = 1/x and n = -n.

    VARIATIONS TO REMEMBER:
    ----------
    - Same square-and-multiply idea powers modular exponentiation
      (see count_good_numbers.cpp).
    - Iterative version avoids recursion stack by looping while halving
      the exponent (used in matrix exponentiation too).

    TIME COMPLEXITY  : O(n) brute / O(log n) optimal -> halving n each call
    SPACE COMPLEXITY : O(n) brute / O(log n) optimal -> recursion call stack depth
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// O(n) time complexity solution for calculating x raised to the power n using recursion
class Solution {
public:
    double calcPow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }

        return x * calcPow(x, n - 1);
    }

    double myPow(double x, int n) {
        long long exp = n;  // Convert n to long long to handle negative values correctly
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        return calcPow(x, exp);
    }
};

// O(log n) time complexity solution for calculating x raised to the power n using recursion
class Solution {
public:
    double calcPow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }

        // Use one recursive call only and store intermediate result
        double half = calcPow(x, n / 2);

        if (n % 2 == 0) {
            return half * half;  // If n is even
        } else {
            return x * half * half;  // If n is odd
        }
    }

    double myPow(double x, int n) {
        long long exp = n;  // Convert n to long long to handle negative values correctly
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        return calcPow(x, exp);
    }
};

int main() {
    return 0;
}