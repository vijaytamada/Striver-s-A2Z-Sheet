/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : Lambda Functions
    ============================================================

    WHAT & WHY:
    ----------
    - A lambda is a nameless, inline function - useful for short one-off
      logic (comparators, predicates) without writing a separate function.
    - Very commonly passed into STL algorithms like sort, count_if, etc.

    KEY POINTS:
    ----------
    1. Syntax: [capture](parameters) -> return_type { body }. Return type
       is usually auto-deduced, so it can be omitted.
    2. [] -> captures nothing, [x] -> captures x by value (a copy),
       [&x] -> captures x by reference, [=] / [&] -> capture everything
       by value / by reference.
    3. Can be stored in a variable with auto (auto f = [](){...};) and
       called later like a normal function.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Capturing by reference ([&]) to a local variable that goes out of
      scope leads to dangling references - be careful with async/stored
      lambdas.
    - Capture by value takes a snapshot at creation time - later changes
      to the original variable won't be seen inside the lambda.
    ============================================================
*/

// [capture](parameters) -> return_type {
//     // function body
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Lambda function examples
    auto greet = []() {
        cout << "Hello, Vijay!" << endl;
    };
    greet();  // Output: Hello, Vijay!

    // Lamda with parameters and return type
    auto add = [](int a, int b) {
        return a + b;
    };
    cout << add(3, 4);  // Output: 7

    // Lambda with capture by value
    int x = 10, y = 20;
    auto sum = [x, y]() {
        return x + y;
    };

    return 0;
}