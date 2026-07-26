/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Conditional Statements
    ============================================================

    WHAT & WHY:
    ----------
    - Conditionals let the program choose different paths based on a condition.
    - Covers plain if-else, if-else-if ladder, and nested if-else.

    KEY POINTS:
    ----------
    1. `if (condition)` runs the block only when condition is true (non-zero).
    2. `else if` chains let you check multiple conditions in order, top to bottom.
    3. Nested if-else = an if-else block inside another if-else block.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Forgetting `{}` around multi-line blocks (only the next single statement
      gets attached to the if).
    - Order matters in an if-else-if ladder — first matching condition wins.
    ============================================================
*/
#include <iostream>
using namespace std;

int main() {
        // simple if-else
    int num = 5;

    if (num % 2 == 0) {
        cout << "Even number";
    } else {
        cout << "Odd number";
    }

    // if-else-if ladder
    int marks = 85;
    if (marks >= 90) {
        cout << "Grade A";
    } else if (marks >= 75) {
        cout << "Grade B";
    } else if (marks >= 60) {
        cout << "Grade C";
    } else {
        cout << "Grade D";
    }

    // nested if else
    num = -3;
    if (num >= 0) {
        if (num == 0) {
            cout << "Zero";
        } else {
            cout << "Positive number";
        }
    } else {
        cout << "Negative number";
    }

    return 0;
}
