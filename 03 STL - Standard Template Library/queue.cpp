/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : queue (FIFO)
    ============================================================

    WHAT & WHY:
    ----------
    - queue is a First-In-First-Out structure - the first element pushed
      is the first one popped. Used for BFS, task scheduling, buffering.

    KEY POINTS:
    ----------
    1. push() -> adds to the back, O(1).
    2. pop() -> removes from the front, O(1). Note: pop() doesn't return
       the value - use front() first if you need it.
    3. front() / back() -> peek at the oldest / newest element, O(1).
    4. empty() / size() -> check state before popping to avoid UB.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Calling pop() or front() on an empty queue is undefined behavior -
      always check empty() first.
    - queue doesn't support iteration or random access - it's strictly
      front/back only (use deque if you need more flexibility).
    ============================================================
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    // --- BASIC QUEUE OPERATIONS ---
    queue<int> q;

    // Push elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // 10
    cout << "Back element: " << q.back() << endl;   // 30

    // Pop element
    q.pop(); // removes 10
    cout << "After pop, front: " << q.front() << endl; // 20

    // Check size and empty
    cout << "Size: " << q.size() << endl;
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    // --- QUEUE WITH STRINGS ---
    queue<string> names;
    names.push("Vijay");
    names.push("DSA");
    names.push("C++");

    cout << "\nNames queue:\n";
    while (!names.empty()) {
        cout << names.front() << endl;
        names.pop();
    }

    // --- SIMULATING A TASK QUEUE ---
    queue<string> tasks;
    tasks.push("Read STL");
    tasks.push("Solve 2 problems");
    tasks.push("Revise strings");
    cout << "\nTask queue:\n";
    while (!tasks.empty()) {
        cout << "Processing: " << tasks.front() << endl;
        tasks.pop();
    }

    return 0;
}