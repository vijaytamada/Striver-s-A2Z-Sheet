/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Variables and Data Types
    ============================================================

    WHAT & WHY:
    ----------
    - A variable is a named slot in memory that holds a value of a specific type.
    - Different types (int, float, double, char, bool) exist because different
      kinds of data need different amounts of memory and precision.

    KEY POINTS:
    ----------
    1. `int` for whole numbers, `float`/`double` for decimals (double = more precision).
    2. `char` holds a single character, `bool` holds true/false.
    3. `auto` lets the compiler figure out the type from the assigned value.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Mixing up `float` and `double` — `float` loses precision on large/decimal numbers.
    - Forgetting the `f` suffix on float literals (e.g. `3.14f`) makes it a double.
    ============================================================
*/
#include <iostream>
using namespace std;

int main() {
    int age = 21;
    float pi = 3.14f;
    double bigPi = 3.1415926535;
    char grade = 'A';
    bool isCodingFun = true;
    auto x = 42;  // type deduced as int

    cout << "Age: " << age << "\nPi: " << pi
         << "\nBig Pi: " << bigPi
         << "\nGrade: " << grade
         << "\nCoding fun? " << isCodingFun
         << "\nAuto type x: " << x << endl;
    return 0;
}
