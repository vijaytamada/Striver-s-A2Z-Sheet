/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : pair
    ============================================================

    WHAT & WHY:
    ----------
    - pair<T1, T2> bundles two values of (possibly different) types
      together - handy for returning two values, or storing (key, value)
      / (index, value) style data without defining a struct.

    KEY POINTS:
    ----------
    1. Access members via .first and .second - O(1), just field access.
    2. Create with pair<T1,T2> p(a, b), make_pair(a, b), or brace-init {a, b}.
    3. Can be nested: pair<int, pair<string, float>> for grouping 3+ values.
    4. Works naturally inside vectors/maps as vector<pair<...>> or
       map<K, pair<...>>.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Field names are always .first/.second - not descriptive, so for
      complex data a struct is more readable than a pair.
    - Comparison operators compare .first first, then .second (lexicographic) -
      useful when sorting a vector of pairs.
    ============================================================
*/

#include <iostream>
#include <utility>   // for std::pair
#include <vector>
using namespace std;

int main() {
    // --- BASIC INITIALIZATION ---
    pair<int, string> p1(1, "Vijay");
    pair<int, string> p2 = make_pair(2, "DSA");
    pair<int, string> p3 = {3, "C++"};

    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;
    cout << "p3: " << p3.first << ", " << p3.second << endl;

    // --- MODIFYING PAIR VALUES ---
    p1.first = 10;
    p1.second = "Updated";
    cout << "Modified p1: " << p1.first << ", " << p1.second << endl;

    // --- USING PAIR IN VECTOR ---
    vector<pair<int, string>> students;
    students.push_back({101, "Alice"});
    students.push_back(make_pair(102, "Bob"));
    students.emplace_back(103, "Charlie");

    cout << "\nStudent list:\n";
    for (auto &student : students) {
        cout << "Roll: " << student.first << ", Name: " << student.second << endl;
    }

    // --- NESTED PAIR ---
    pair<int, pair<string, float>> nested = {1, {"Math", 95.5}};
    cout << "\nNested pair:\n";
    cout << "ID: " << nested.first << ", Subject: " << nested.second.first << ", Marks: " << nested.second.second << endl;

    return 0;
}