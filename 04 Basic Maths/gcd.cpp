/*
    ============================================================
    TOPIC   : Basic Maths
    PROBLEM : GCD (Greatest Common Divisor) - Euclidean Algorithm
    ============================================================

    INTUITION:
    ----------
    - GCD(a, b) is the same as GCD(b, a % b) - because any number that
      divides both a and b also divides (a % b).
    - Keep shrinking the pair using modulo until one becomes 0; the other
      is the answer. This file shows both an iterative and a recursive
      version of the same idea.

    STEPS:
    ----------
    1. (Iterative) Set divisor = smaller, dividend = larger; repeatedly
       replace dividend with divisor and divisor with the remainder until
       the remainder is 0 - the last divisor is the GCD.
    2. (Recursive) Base case: if b == 0, return a. Otherwise return
       gcdRecursive(b, a % b).

    VARIATIONS TO REMEMBER:
    ----------
    - LCM(a, b) = (a * b) / GCD(a, b).
    - GCD of an array = fold GCD across all elements.
    - C++17 also has a built-in std::gcd() in <numeric>.

    TIME COMPLEXITY  : O(log(min(a, b))) -> each step shrinks numbers fast
    SPACE COMPLEXITY : O(1) iterative, O(log(min(a, b))) recursion stack for recursive
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Iterative function to return gcd of a and b
// Take two numbers and find the smaller one as the divisor and the larger one as the dividend. Repeatedly divide the dividend by the divisor and find the remainder. Replace the dividend with the divisor and the divisor with the remainder. Continue this process until the remainder becomes 0. The final divisor is the GCD of the two numbers.

// Time Complexity: O(log(min(a, b))) in the worst case, where a and b are the two input numbers. This is because in each step, we are reducing the size of the problem by at least half.
int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    int divisor = min(a, b);
    int dividend = max(a, b);

    while (dividend % divisor != 0) {
        int rem = dividend % divisor;
        dividend = divisor;
        divisor = rem;
    }

    return divisor;
}

// Recursive function to return gcd of a and b
// Use the Euclidean algorithm with recursion. If the second number becomes 0, return the first number as the GCD. Otherwise, call the function again with the second number and the remainder of the first number divided by the second. This process continues until the base condition is reached.
// Intuition:
// The key idea is that the GCD of two numbers does not change if we replace the larger number with the remainder when divided by the smaller number. We keep reducing the problem size until one number becomes 0, and the other number will be the GCD.

// Time Complexity: O(log(min(a, b))) in the worst case, where a and b are the two input numbers. This is because in each step, we are reducing the size of the problem by at least half.
int gcdRecursive(int a, int b) {
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "GCD (Iterative): " << gcd(a, b) << endl;
    cout << "GCD (Recursive): " << gcdRecursive(a, b) << endl;
    return 0;
}