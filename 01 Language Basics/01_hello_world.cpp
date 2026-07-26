/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Hello World / Basic Program Structure
    ============================================================

    WHAT & WHY:
    ----------
    - Every C++ program needs a `main()` function — that's where execution starts.
    - `#include <iostream>` brings in the input/output library so we can use `cout`.
    - This is the smallest possible "does something visible" program, good for
      checking your compiler/setup works.

    KEY POINTS:
    ----------
    1. `cout << "..."` prints text to the console; `<<` is the "insertion" operator.
    2. `endl` prints a newline and flushes the output buffer.
    3. `return 0;` tells the OS the program finished successfully.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Forgetting the semicolon after a statement.
    - Forgetting `using namespace std;` and then having to write `std::cout` everywhere.
    ============================================================
*/
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
