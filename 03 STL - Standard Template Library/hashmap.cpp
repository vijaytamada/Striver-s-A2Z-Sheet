/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : map vs unordered_map (Hash Maps / Ordered Maps)
    ============================================================

    WHAT & WHY:
    ----------
    - Both store key-value pairs. map keeps keys sorted (implemented as a
      balanced BST); unordered_map does not (implemented as a hash table).
    - Use unordered_map when you just need fast lookups; use map when you
      need sorted order or range queries.

    KEY POINTS:
    ----------
    1. operator[] on either -> inserts key with default value if missing,
       so watch out for accidental insertion when just "checking" a key.
    2. map: insert/find/erase are O(log n). unordered_map: O(1) average,
       O(n) worst case (hash collisions).
    3. Use find() to check existence without inserting; compare to end().
    4. Structured bindings: for (auto &[key, val] : m) makes iteration clean.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - unordered_map has no guaranteed iteration order - don't rely on it.
    - m[key] on a const map won't compile (operator[] can insert, so it's
      non-const); use .at(key) or find() for read-only/const access.
    ============================================================
*/

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    // --- std::map (ordered) ---
    map<int, string> orderedMap;
    orderedMap[3] = "C++";
    orderedMap[1] = "DSA";
    orderedMap[2] = "Vijay";

    cout << "Ordered map:\n";
    for (auto &entry : orderedMap) {
        cout << entry.first << " => " << entry.second << endl;
    }

    // --- std::unordered_map (unordered) ---
    unordered_map<int, string> unorderedMap;
    unorderedMap[3] = "C++";
    unorderedMap[1] = "DSA";
    unorderedMap[2] = "Vijay";
    unorderedMap.insert({3, "Uzma"});

    cout << "\nUnordered map:\n";
    for (auto &entry : unorderedMap) {
        cout << entry.first << " => " << entry.second << endl;
    }

    // One for traversing
    for (auto &[key, val] : unorderedMap) {
        cout << key << " -> " << val << endl;
    }

    // --- Common Operations ---
    cout << "\nAccessing key 2 in map: " << orderedMap[2] << endl;
    cout << "Accessing key 2 in unordered_map: " << unorderedMap[2] << endl;

    // Check existence
    if (unorderedMap.find(4) == unorderedMap.end()) {
        cout << "Key 4 not found in unordered_map\n";
    }

    // Erase key
    orderedMap.erase(1);
    cout << "\nAfter erasing key 1 from orderedMap:\n";
    for (auto &entry : orderedMap) {
        cout << entry.first << " => " << entry.second << endl;
    }

    unorderedMap.clear();
    cout << "\nAfter clearing unorderedMap, size: " << unorderedMap.size() << endl;

    unordered_map<string, int> fm;
    fm["Vijay"] = 1;
    fm["Uzma"] = 2;

    cout << "\nFrequency map:\n";
    for (auto &[name, freq] : fm) {
        cout << name << " -> " << freq << endl;
    }

    return 0;
}