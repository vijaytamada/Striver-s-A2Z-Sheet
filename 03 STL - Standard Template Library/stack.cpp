/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : stack (LIFO)
    ============================================================

    WHAT & WHY:
    ----------
    - stack is a Last-In-First-Out structure - the most recently pushed
      element is the first one popped. Used for undo operations, matching
      brackets, DFS, expression evaluation.

    KEY POINTS:
    ----------
    1. push() -> adds to the top, O(1).
    2. pop() -> removes the top element, O(1). Like queue, pop() returns
       nothing - call top() before popping if you need the value.
    3. top() -> peek at the most recently pushed element, O(1).
    4. empty() / size() -> check state before popping to avoid UB.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Calling pop() or top() on an empty stack is undefined behavior -
      always check empty() first.
    - stack has no iteration/traversal support - only the top is
      accessible at any time.
    ============================================================
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    // --- BASIC STACK OPERATIONS ---
    stack<int> s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // 30

    // Pop element
    s.pop();
    cout << "After pop, top: " << s.top() << endl; // 20

    // Check size and empty
    cout << "Size: " << s.size() << endl;
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << endl;

    // --- STACK WITH STRINGS ---
    stack<string> names;
    names.push("Vijay");
    names.push("DSA");
    names.push("C++");

    cout << "\nNames stack:\n";
    while (!names.empty()) {
        cout << names.top() << endl;
        names.pop();
    }

    // --- STACK INITIALIZATION FROM ARRAY (manual) ---
    int arr[] = {1, 2, 3, 4, 5};
    stack<int> s2;
    for (int i = 0; i < 5; ++i) {
        s2.push(arr[i]);
    }

    cout << "\nStack from array:\n";
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    return 0;
}