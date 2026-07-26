/*
    ============================================================
    TOPIC   : Basic Recursion
    PROBLEM : Nth Fibonacci Number
    ============================================================

    INTUITION:
    ----------
    - Each Fibonacci number is the sum of the two before it:
      fib(n) = fib(n-1) + fib(n-2). Recursion directly expresses this
      definition - trust the two smaller calls and add their results.

    STEPS:
    ----------
    1. Base cases: fib(0) = 0, fib(1) = 1.
    2. Otherwise, return fib(n-1) + fib(n-2).
    3. This branches into two recursive calls per level, forming a
       recursion tree.

    VARIATIONS TO REMEMBER:
    ----------
    - This naive version recomputes the same subproblems many times -
      memoization (top-down DP) or an iterative bottom-up loop fixes that
      and brings it down to O(n).
    - Iterative O(1) space version: just keep last two values in variables.

    TIME COMPLEXITY  : O(2^n) -> each call branches into two more calls (no memoization)
    SPACE COMPLEXITY : O(n) -> max recursion stack depth
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    // base case
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);  // recursive call
}

int main() {
    cout << fibonacci(5) << endl;  // Output: 5
    return 0;
}