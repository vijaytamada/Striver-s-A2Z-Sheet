/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Namespaces
    ============================================================

    WHAT & WHY:
    ----------
    - A namespace groups related names (functions, variables, classes) under
      one label, to avoid naming conflicts between different parts of code.
    - Here, two namespaces (`First`, `Second`) each define their own `hello()`
      without clashing.

    KEY POINTS:
    ----------
    1. Access a namespace member with `NamespaceName::member` (scope resolution operator).
    2. `using namespace X;` brings all of X's names into the current scope, so
       you can call them without the prefix.
    3. `std` (as in `using namespace std;`) is itself just a namespace.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Overusing `using namespace X;` in large projects can cause name collisions.
    - After `using namespace First;`, calling `hello()` becomes ambiguous if
      `Second` is also brought in the same way.
    ============================================================
*/
#include <iostream>
using namespace std;

// namespace First
namespace First {
    void hello() {
        cout << "Hello from First namespace" << endl;
    }
}  

// namespace Second
namespace Second {
    void hello() {
        cout << "Hello from Second namespace" << endl;
    }
}  

int main() {
    First::hello();
    Second::hello();

    using namespace First;  // now can call hello() directly
    hello();
    return 0;
}
