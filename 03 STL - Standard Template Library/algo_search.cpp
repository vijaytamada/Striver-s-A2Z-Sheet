/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : Searching Algorithms (find, binary_search, lower_bound, upper_bound)
    ============================================================

    WHAT & WHY:
    ----------
    - <algorithm> gives ready-made search functions so you don't hand-roll
      linear/binary search every time.
    - find() works on any range (sorted or not). binary_search/lower_bound/
      upper_bound need a SORTED range but are much faster.

    KEY POINTS:
    ----------
    1. find(begin, end, val) -> O(n) linear scan, returns iterator (end() if not found).
    2. binary_search(begin, end, val) -> O(log n), returns bool only.
    3. lower_bound(begin, end, val) -> O(log n), iterator to first element >= val.
    4. upper_bound(begin, end, val) -> O(log n), iterator to first element > val.
    5. distance(begin, it) converts an iterator position to an index.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - binary_search/lower_bound/upper_bound give garbage results on an
      unsorted range - always sort() first.
    - lower_bound/upper_bound return end() (not -1) when nothing qualifies -
      check before dereferencing.
    ============================================================
*/

#include <iostream>
#include <vector>
#include <algorithm> // for find, binary_search, lower_bound, upper_bound
using namespace std;

// --- Custom class ---
class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}
};

// --- Comparator for lower_bound by age ---
bool compareByAge(const Person &p1, const Person &p2) {
    return p1.age < p2.age;
}

int main() {
    // --- Linear Search using find() ---
    vector<int> nums = {10, 20, 30, 40, 50};
    auto it = find(nums.begin(), nums.end(), 30);
    if (it != nums.end()) {
        cout << "Found 30 at index: " << distance(nums.begin(), it) << endl;
    } else {
        cout << "30 not found\n";
    }

    // --- Binary Search (sorted vector) ---
    sort(nums.begin(), nums.end()); // required for binary_search
    int target = 40;
    bool found = binary_search(nums.begin(), nums.end(), target);
    cout << "Binary search for " << target << ": " << (found ? "Found" : "Not Found") << endl;

    // --- lower_bound and upper_bound ---
    auto lb = lower_bound(nums.begin(), nums.end(), 30); // first >= 30
    int idx = lb - nums.begin();
    auto ub = upper_bound(nums.begin(), nums.end(), 30); // first > 30
    cout << "lower_bound of 30 at index: " << distance(nums.begin(), lb) << endl;
    cout << "upper_bound of 30 at index: " << distance(nums.begin(), ub) << endl;

    return 0;
}