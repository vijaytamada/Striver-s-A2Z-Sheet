/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Functions
    ============================================================

    WHAT & WHY:
    ----------
    - A function is a reusable, named block of code — write once, call many times.
    - Helps break a program into smaller, testable, readable pieces.

    KEY POINTS:
    ----------
    1. A function signature = return type + name + parameter list.
    2. `void` means the function returns nothing.
    3. Functions can take zero or more parameters and can optionally return a value.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Forgetting `return` in a non-void function (undefined behavior).
    - Calling a function before it's declared/defined (needs a prototype or
      must be defined earlier in the file).
    ============================================================
*/
#include <iostream>
using namespace std;

// 1. No args, no return
void greet() {
    cout << "Hello, world!" << endl;
}

// 2. With args, no return
void printSquare(int x) {
    cout << "Square: " << x * x << endl;
}

// 3. No args, with return
int getNumber() {
    return 42;
}

// 4. With args, with return
int add(int a, int b) {
    return a + b;
}

int main() {
    greet();

    printSquare(5);

    int num = getNumber();
    cout << "Number: " << num << endl;

    int sum = add(10, 20);
    cout << "Sum: " << sum << endl;

    return 0;
}
