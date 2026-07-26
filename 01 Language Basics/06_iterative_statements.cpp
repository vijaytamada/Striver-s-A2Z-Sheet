/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Iterative Statements (Loops)
    ============================================================

    WHAT & WHY:
    ----------
    - Loops repeat a block of code until a condition is no longer true.
    - This file covers the 4 main loop forms: for, while, do-while, range-based for.

    KEY POINTS:
    ----------
    1. `for` is best when you know the number of iterations in advance.
    2. `while` checks the condition before each run; `do-while` checks after
       (so a do-while body always runs at least once).
    3. Range-based `for (auto val : arr)` iterates directly over container/array elements.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Infinite loops from forgetting to update the loop variable.
    - Off-by-one errors with `<` vs `<=` in the loop condition.
    ============================================================
*/
#include <iostream>
using namespace std;

int main() {
    cout << "--- For Loop ---" << endl;
    for (int i = 1; i <= 5; ++i) {
        cout << i << " ";
    }
    cout << endl;

    cout << "--- While Loop ---" << endl;
    int j = 1;
    while (j <= 5) {
        cout << j << " ";
        j++;
    }
    cout << endl;

    cout << "--- Do-While Loop ---" << endl;
    int k = 1;
    do {
        cout << k << " ";
        k++;
    } while (k <= 5);
    cout << endl;

    cout << "--- Range-based For Loop with auto ---" << endl;
    int arr[] = {10, 20, 30, 40, 50};
    for (auto val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
