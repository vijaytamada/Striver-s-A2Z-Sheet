/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : sort() with Default Order, greater<>, and Custom Comparators
    ============================================================

    WHAT & WHY:
    ----------
    - sort() from <algorithm> sorts any range in-place using introsort
      (quicksort + heapsort + insertion sort blend) - fast and reliable.
    - Use a comparator function/lambda when sorting custom objects or by
      a non-default order (e.g. descending, or by a specific field).

    KEY POINTS:
    ----------
    1. sort(begin, end) -> O(n log n), ascending by default (uses operator<).
    2. sort(begin, end, greater<int>()) -> descending order, no custom function needed.
    3. sort(begin, end, comparatorFn) -> comparatorFn(a, b) should return true
       if a must come before b.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - sort() is NOT stable by default - equal elements may get reordered
      (use stable_sort if order among equals matters).
    - Comparator must implement strict weak ordering (never return true for
      compare(a, a)), otherwise undefined behavior/crashes.
    ============================================================
*/

#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// --- Custom class ---
class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}
};

// --- Comparator to sort by age (ascending) ---
bool compareByAge(const Person &p1, const Person &p2) {
    return p1.age < p2.age;
}

// --- Comparator to sort by name (lexicographically) ---
bool compareByName(const Person &p1, const Person &p2) {
    return p1.name < p2.name;
}

int main() {
    // --- Sorting integers ---
    vector<int> nums = {40, 10, 30, 20};

    // Ascending
    sort(nums.begin(), nums.end());
    cout << "Ascending sort: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // Descending
    sort(nums.begin(), nums.end(), greater<int>());
    cout << "Descending sort: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // --- Sorting custom objects ---
    vector<Person> people = {
        Person("Vijay", 25),
        Person("Alice", 30),
        Person("Bob", 20)
    };

    // Sort by age
    sort(people.begin(), people.end(), compareByAge);
    cout << "\nSorted by age:\n";
    for (const Person &p : people) {
        cout << p.name << " (" << p.age << ")\n";
    }

    // Sort by name
    sort(people.begin(), people.end(), compareByName);
    cout << "\nSorted by name:\n";
    for (const Person &p : people) {
        cout << p.name << " (" << p.age << ")\n";
    }

    return 0;
}