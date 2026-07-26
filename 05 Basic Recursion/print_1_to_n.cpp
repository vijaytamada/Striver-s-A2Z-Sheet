/*
    ============================================================
    TOPIC   : Basic Recursion
    PROBLEM : Print Numbers from 1 to N (using recursion)
    ============================================================

    INTUITION:
    ----------
    - To print 1..n in increasing order, first let recursion print 1..n-1,
      THEN print n. The print statement placed AFTER the recursive call
      means printing happens on the way back up (unwinding phase), so
      smaller numbers get printed first.

    STEPS:
    ----------
    1. Base case: if n == 0, return (stop recursing).
    2. Recursive call: print(n - 1) first.
    3. After that call returns, print n.

    VARIATIONS TO REMEMBER:
    ----------
    - Print statement BEFORE the recursive call instead would print
      n down to 1 (see print_n_to_1.cpp) - placement controls order.
    - Purely iterative version is trivial with a for loop; recursion here
      is for practicing call-stack intuition.

    TIME COMPLEXITY  : O(n) -> one call per number from n down to 0
    SPACE COMPLEXITY : O(n) -> recursion call stack depth
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void print(int n) {
    if (n == 0)
        return;

    print(n - 1);

    cout << n << " ";
}

int main() {
    print(5);
    return 0;
}