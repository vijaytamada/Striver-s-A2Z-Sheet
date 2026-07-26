/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : set vs unordered_set (Hash Set / Ordered Set)
    ============================================================

    WHAT & WHY:
    ----------
    - Both store unique elements only (duplicates auto-ignored). set keeps
      them sorted (BST); unordered_set does not (hash table).
    - Great for "have I seen this before" checks and removing duplicates.

    KEY POINTS:
    ----------
    1. insert() silently ignores duplicates - no error, no effect.
    2. set: insert/find/erase are O(log n). unordered_set: O(1) average.
    3. count(val) returns 0 or 1 (since elements are unique) - handy as a
       quick boolean existence check.
    4. find(val) returns an iterator; compare against end() to check
       existence, same pattern as maps.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - unordered_set iteration order is unspecified and can even change
      between runs - never rely on it for output order.
    - set only stores each value once - if you need counts, use a map
      instead of a set.
    ============================================================
*/

#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    // --- std::set (ordered) ---
    set<int> orderedSet;
    orderedSet.insert(30);
    orderedSet.insert(10);
    orderedSet.insert(20);
    orderedSet.insert(10); // duplicate ignored

    cout << "Ordered set:\n";
    for (int x : orderedSet) {
        cout << x << " "; // prints in ascending order
    }
    cout << endl;

    // --- std::unordered_set (unordered) ---
    unordered_set<int> unorderedSet;
    unorderedSet.insert(30);
    unorderedSet.insert(10);
    unorderedSet.insert(20);
    unorderedSet.insert(10); // duplicate ignored

    cout << "\nUnordered set:\n";
    for (int x : unorderedSet) {
        cout << x << " "; // no specific order
    }
    cout << endl;
    
    // --- Common Operations ---
    cout << "\nCheck if 20 exists in orderedSet: ";
    cout << (orderedSet.count(20) ? "Yes" : "No") << endl;

    // check existence
    cout << "Check if 25 exists in unorderedSet: ";
    cout << (unorderedSet.find(25) != unorderedSet.end() ? "Yes" : "No") << endl;

    cout << "Erase 10 from unorderedSet\n";
    unorderedSet.erase(10);

    cout << "Unordered set after erase:\n";
    for (int x : unorderedSet) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}