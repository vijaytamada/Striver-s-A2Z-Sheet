/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Operators
    ============================================================

    WHAT & WHY:
    ----------
    - Operators let you combine/compare/manipulate values: arithmetic, assignment,
      comparison, logical, and bitwise.
    - Knowing bitwise operators well matters a lot for DSA (masks, XOR tricks, etc).

    KEY POINTS:
    ----------
    1. Arithmetic: `+ - * / %` — `%` (modulo) only works on integers.
    2. Comparison returns a bool (0 or 1): `== != > < >= <=`.
    3. Bitwise: `& | ^ ~ << >>` operate on the binary representation of integers.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Integer division truncates (`10 / 3 == 3`, not 3.33).
    - Mixing up `=` (assignment) with `==` (comparison).
    - `<<` and `>>` are both stream operators AND bit-shift operators depending on context.
    ============================================================
*/
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;

    // Arithmetic Operators
    cout << "--- Arithmetic Operators ---" << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;
    cout << "a % b = " << (a % b) << endl;

    // Assignment Operators
    int c = a;
    c += b;
    cout << "--- Assignment Operators ---" << endl;
    cout << "c += b gives: " << c << endl;
    c -= b;
    cout << "c -= b gives: " << c << endl;
    c *= b;
    cout << "c *= b gives: " << c << endl;
    c /= b;
    cout << "c /= b gives: " << c << endl;

    // Comparison (Relational) Operators
    cout << "--- Comparison Operators ---" << endl;
    cout << "a == b : " << (a == b) << endl;
    cout << "a != b : " << (a != b) << endl;
    cout << "a > b  : " << (a > b) << endl;
    cout << "a < b  : " << (a < b) << endl;

    // Logical Operators
    bool x = true, y = false;
    cout << "--- Logical Operators ---" << endl;
    cout << "x && y : " << (x && y) << endl;
    cout << "x || y : " << (x || y) << endl;
    cout << "!x     : " << (!x) << endl;

    // Bitwise Operators
    cout << "--- Bitwise Operators ---" << endl;
    cout << "a & b = " << (a & b) << endl;
    cout << "a | b = " << (a | b) << endl;
    cout << "a ^ b = " << (a ^ b) << endl;
    cout << "~a    = " << (~a) << endl;
    cout << "a << 1 = " << (a << 1) << endl;
    cout << "a >> 1 = " << (a >> 1) << endl;

    return 0;
}
