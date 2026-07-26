/*
    ============================================================
    TOPIC   : Basic Recursion
    PROBLEM : Factorial of a Number
    ============================================================

    INTUITION:
    ----------
    - Factorial(n) = n * Factorial(n-1). Recursion mirrors this definition
      directly: trust that factorial(n-1) works, and just multiply by n.
    - Base case factorial(0) = 1 stops the recursion.

    STEPS:
    ----------
    1. Base case: if n == 0, return 1.
    2. Otherwise, return n * factorial(n - 1).
    3. Each call waits for the smaller subproblem to resolve, then
       multiplies in n on the way back up (the "unwinding" phase).

    VARIATIONS TO REMEMBER:
    ----------
    - Can be written iteratively with a simple for loop - no recursion
      overhead, useful when stack depth is a concern.
    - Watch for integer overflow for n > ~12 with int (factorial grows fast).

    TIME COMPLEXITY  : O(n) -> one call per value from n down to 0
    SPACE COMPLEXITY : O(n) -> recursion call stack depth
    ============================================================
*/

// Calculate the factorial of a number using recursion. Define a base case where the factorial of 0 is 1. For other values, multiply the number by the factorial of the previous number and continue calling the function until the base case is reached.

// Intuition:
// Factorial means multiplying a number by all smaller positive numbers. Recursion breaks this problem into smaller parts by reducing the number step by step until it reaches 0, then builds the answer back up.

#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    // base case
    if (n == 0) return 1;

    return n * factorial(n - 1); // recursive call
}

int main()
{
    cout << factorial(5) << endl; // Output: 120
    return 0;
}