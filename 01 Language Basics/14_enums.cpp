/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Enums
    ============================================================

    WHAT & WHY:
    ----------
    - An `enum` defines a type that can only hold one of a fixed set of named
      values — makes code more readable than using raw numbers (magic numbers).
    - Here `Color` can only be RED, GREEN, or BLUE.

    KEY POINTS:
    ----------
    1. By default, enum values are just integers starting from 0 (RED=0, GREEN=1, BLUE=2).
    2. You can compare enum values directly with `==`.
    3. `enum class` (not used here) is a safer, scoped version that avoids name clashes.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Plain `enum` values leak into the surrounding scope, so names can clash.
    - Assigning an out-of-range integer to an enum variable is technically undefined behavior.
    ============================================================
*/
#include <iostream>
using namespace std;

// Enum example
enum Color { RED,
             GREEN,
             BLUE };

int main() {
    Color c = GREEN;

    if (c == GREEN) {
        cout << "The color is GREEN" << endl;
    }

    return 0;
}
