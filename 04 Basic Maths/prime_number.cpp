/*
    ============================================================
    TOPIC   : Basic Maths
    PROBLEM : Check if a Number is Prime (Optimized)
    ============================================================

    INTUITION:
    ----------
    - If n has a factor bigger than sqrt(n), it must pair with a factor
      smaller than sqrt(n), so checking divisors only up to sqrt(n) is
      enough - no need to check all the way to n.
    - Even numbers > 2 are never prime, so we can skip every other check.

    STEPS:
    ----------
    1. Handle base cases: n <= 1 -> not prime, n == 2 -> prime, even n -> not prime.
    2. Loop i from 3 to sqrt(n), stepping by 2 (odd numbers only).
    3. If any i divides n exactly, n is not prime.
    4. If no divisor found, n is prime.

    VARIATIONS TO REMEMBER:
    ----------
    - For checking primality of MANY numbers up to N, use the Sieve of
      Eratosthenes instead (O(N log log N) total) rather than calling this
      per number.
    - Naive approach checks up to n instead of sqrt(n) - much slower, good
      to mention as the "brute force" starting point.

    TIME COMPLEXITY  : O(sqrt(n)) -> only checks odd divisors up to sqrt(n)
    SPACE COMPLEXITY : O(1) -> no extra space used
    ============================================================
*/

// Take a number as input and check if it is prime using an optimized method. First, handle special cases like numbers less than or equal to 1, 2, and even numbers. Then, check divisibility only from 3 up to the square root of the number, skipping even numbers. If any divisor is found, the number is not prime; otherwise, it is prime.

// Intuition:
// If a number has a factor greater than its square root, it must also have a factor smaller than the square root. So, it is enough to check divisibility only up to √n. Skipping even numbers further reduces unnecessary checks and makes the algorithm faster.

// Time Complexity: O(√n) in the worst case, where n is the input number. This is because we are checking for divisibility only up to the square root of n, which reduces the number of checks significantly compared to a naive approach that checks up to n.

#include <cmath>  // for sqrt
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPrime(num))
        cout << num << " is a prime number.\n";
    else
        cout << num << " is not a prime number.\n";

    return 0;
}