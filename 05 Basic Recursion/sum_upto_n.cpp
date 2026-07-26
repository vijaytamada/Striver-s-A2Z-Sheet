/*
    ============================================================
    TOPIC   : Basic Recursion
    PROBLEM : Sum of Numbers from 1 to N
    ============================================================

    INTUITION:
    ----------
    - Sum(n) = n + Sum(n-1). Trust that findSum(n-1) correctly computes
      the sum of everything before n, then just add n to it.

    STEPS:
    ----------
    1. Base case: if n == 0, return 0.
    2. Otherwise, return n + findSum(n - 1).

    VARIATIONS TO REMEMBER:
    ----------
    - Closed-form formula n*(n+1)/2 computes this in O(1) - mention as the
      optimal approach; recursion here is for practicing the pattern.
    - Same additive-accumulation shape as factorial.cpp, just + instead of *.

    TIME COMPLEXITY  : O(n) -> one call per value from n down to 0
    SPACE COMPLEXITY : O(n) -> recursion call stack depth
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

int findSum(int n) {
    if (n == 0)
        return 0;

    return n + findSum(n - 1);
}

int main() {
    cout << findSum(5);
    return 0;
}