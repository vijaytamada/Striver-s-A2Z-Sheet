/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : Iterators (begin/end, rbegin/rend, next/prev, distance)
    ============================================================

    WHAT & WHY:
    ----------
    - An iterator is like a generalized pointer that lets you walk through
      any STL container the same way, regardless of its internal structure.
    - Needed for using <algorithm> functions and for manual traversal/
      insertion/erasure at specific positions.

    KEY POINTS:
    ----------
    1. begin()/end() -> forward traversal; end() points PAST the last element.
    2. rbegin()/rend() -> reverse traversal without physically reversing data.
    3. next(it, n)/prev(it, n) -> get an iterator offset by n, without moving
       the original iterator.
    4. distance(it1, it2) -> number of steps between two iterators (used to
       turn an iterator into an index).

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Dereferencing end() (or rend()) is undefined behavior - it's a
      sentinel, not a real element.
    - Range-based for loops (for (auto x : nums)) use iterators internally,
      so it's usually simpler than writing begin()/end() manually.
    ============================================================
*/

#include <algorithm>  // for binary_search, next, prev, distance
#include <iostream>
#include <iterator>  // for iterator
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {10, 20, 30, 40, 50};

    // --- Using begin() and end() ---
    vector<int>::iterator it = nums.begin();
    vector<int>::iterator it_end = nums.end();

    while (it != it_end) {
        cout << *it << " ";
        ++it;
    }

    cout << "Using begin() and end(): ";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // --- Using rbegin() and rend() ---
    cout << "Using rbegin() and rend(): ";
    for (auto rit = nums.rbegin(); rit != nums.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // --- Range-based for loop with auto ---
    cout << "Range-based loop with auto: ";
    for (auto x : nums) {
        cout << x << " ";
    }
    cout << endl;

    // --- Using next() and prev() ---
    auto it = nums.begin();        // points to 10
    auto it_next = next(it, 2);    // points to 30
    auto it_prev = prev(it_next);  // back to 20

    cout << "\nUsing next() and prev():\n";
    cout << "Element at next(it, 2): " << *it_next << endl;
    cout << "Element at prev(it_next): " << *it_prev << endl;

    // --- Using distance() ---
    int dist = distance(nums.begin(), it_next);
    cout << "Distance from begin to it_next: " << dist << endl;

    return 0;
}