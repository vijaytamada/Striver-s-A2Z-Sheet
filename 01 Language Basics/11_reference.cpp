/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : References (Call by Value vs Call by Reference)
    ============================================================

    WHAT & WHY:
    ----------
    - A reference (`&`) is an alias for an existing variable — no new memory,
      just another name for the same variable.
    - Call by reference lets a function modify the caller's actual variable,
      and avoids copying large objects.

    KEY POINTS:
    ----------
    1. Call by value: function gets a copy — changes inside don't affect the original.
    2. Call by reference: function parameter is `Type &name` — changes inside
       DO affect the original variable.
    3. Unlike pointers, references must be initialized when declared and can't
       be reassigned to refer to something else later.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Forgetting the `&` in the parameter — silently falls back to call by value.
    - Passing large objects by value in performance-sensitive code (unnecessary copy).
    ============================================================
*/
#include <iostream>
using namespace std;

// Call by Value: copies the argument, original variable is not changed
void callByValue(int x) {
    x = x + 10;
    cout << "Inside callByValue function: x = " << x << endl;
}

// Call by Reference: uses reference, original variable is modified
void callByReference(int &x) {
    x = x + 10;
    cout << "Inside callByReference function: x = " << x << endl;
}

int main() {
    int num1 = 5;
    int num2 = 5;

    cout << "Before callByValue: num1 = " << num1 << endl;
    callByValue(num1);
    cout << "After callByValue: num1 = " << num1 << " (unchanged)" << endl;

    cout << "Before callByReference: num2 = " << num2 << endl;
    callByReference(num2);
    cout << "After callByReference: num2 = " << num2 << " (changed)" << endl;

    return 0;
}
