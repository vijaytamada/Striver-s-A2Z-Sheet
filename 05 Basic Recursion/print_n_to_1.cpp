/*
    ============================================================
    TOPIC   : Basic Recursion
    PROBLEM : Print Numbers from N to 1 (using recursion)
    ============================================================

    INTUITION:
    ----------
    - To print n down to 1, print n FIRST, then let recursion handle the
      rest (n-1 down to 1). The print statement placed BEFORE the
      recursive call means printing happens on the way down (before
      unwinding), so larger numbers get printed first.

    STEPS:
    ----------
    1. Base case: if n == 0, return (stop recursing).
    2. Print n immediately.
    3. Recursive call: print(n - 1) to handle the rest.

    VARIATIONS TO REMEMBER:
    ----------
    - Print statement AFTER the recursive call instead would print 1 up
      to n (see print_1_to_n.cpp) - placement controls order.
    - Good contrast pair with print_1_to_n.cpp to internalize
      "before call vs after call" recursion behavior.

    TIME COMPLEXITY  : O(n) -> one call per number from n down to 0
    SPACE COMPLEXITY : O(n) -> recursion call stack depth
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void print(int n) {
    if (n == 0)
        return;

    cout << n << " ";
    print(n - 1);
}

int main() {
    print(5);
    return 0;
}