/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Pointers
    ============================================================

    WHAT & WHY:
    ----------
    - A pointer is a variable that stores the memory address of another variable.
    - Used to directly modify a variable, work with dynamic memory, and avoid
      copying large data when passing to functions.

    KEY POINTS:
    ----------
    1. `&x` gets the address of x. `*p` dereferences pointer p (gets the value).
    2. A pointer's type must match the type of the variable it points to.
    3. `nullptr` means "points to nothing" — always check before dereferencing.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Dereferencing a null/uninitialized pointer crashes the program.
    - Dangling pointer: pointer still points to memory that was already freed.
    ============================================================
*/
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* ptr = &x;

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Pointer value (address): " << ptr << endl;
    cout << "Value via pointer: " << *ptr << endl;

    *ptr = 20; // modify x through pointer
    cout << "New value of x: " << x << endl;

    cout << sizeof(x) << endl;      // Size of int
    cout << sizeof(ptr) << endl;    // Size of pointer

    return 0;
}
