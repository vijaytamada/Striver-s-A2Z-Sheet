/*
    ============================================================
    TOPIC   : Basic Recursion
    PROBLEM : Print "Hello World" N Times
    ============================================================

    INTUITION:
    ----------
    - Instead of a loop, use recursion as the repeat mechanism: print once,
      then call yourself with a smaller n, until n hits the base case.

    STEPS:
    ----------
    1. Base case: if n == 0, return (stop recursing).
    2. Print "Hello World".
    3. Recursively call print(n - 1) to handle the remaining repeats.

    VARIATIONS TO REMEMBER:
    ----------
    - This is the simplest recursion pattern - good template for any
      "do something N times" problem before tackling harder recursion.
    - Equivalent to a simple for loop; recursion here is just for practice.

    TIME COMPLEXITY  : O(n) -> one call per repeat
    SPACE COMPLEXITY : O(n) -> recursion call stack depth
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void print(int n){
    // base case
    if(n == 0) return;

    cout << "Hello World" << endl;
    print(n-1); // recursive call
}

int main()
{
    print(5);
    return 0;
}