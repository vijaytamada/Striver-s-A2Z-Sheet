/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : priority_queue (Heap)
    ============================================================

    WHAT & WHY:
    ----------
    - priority_queue is a heap - it always gives you the "largest" (or
      "smallest", with a custom comparator) element in O(1) via top().
    - Use it whenever you repeatedly need the max/min from a changing set,
      e.g. Dijkstra, top-K problems, scheduling.

    KEY POINTS:
    ----------
    1. push() / pop() -> O(log n). top() -> O(1).
    2. Default priority_queue<int> is a MAX-HEAP (largest on top).
    3. For a MIN-HEAP: priority_queue<int, vector<int>, greater<int>>.
    4. For custom types, pass a comparator class/struct or lambda with
       decltype - operator() should return true when p1 has LOWER priority
       than p2 (i.e. p1 should come out later).

    COMMON PITFALLS / GOTCHAS:
    ----------
    - It's easy to forget priority_queue is max-heap by default - a common
      interview mistake is assuming min-heap.
    - There's no way to iterate or search a priority_queue - you can only
      access top(); pop repeatedly if you need to see everything.
    ============================================================
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Comparator {
public:
    bool operator()(Person &p1, Person &p2) {
        return p1.age > p2.age;  // Min-Heap based on age
    }
};

int main() {
    // --- MAX-HEAP (default) ---
    priority_queue<int> maxPQ;

    maxPQ.push(30);
    maxPQ.push(10);
    maxPQ.push(50);
    maxPQ.push(20);

    cout << "Max-Heap:\n";
    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " ";  // prints in descending order
        maxPQ.pop();
    }
    cout << endl;

    // --- MIN-HEAP using greater<int> ---
    priority_queue<int, vector<int>, greater<int>> minPQ;

    auto cmp = [](int a, int b) { return a > b; };
    priority_queue<int, vector<int>, decltype(cmp)> customMinPQ(cmp);

    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(50);
    minPQ.push(20);

    cout << "\nMin-Heap:\n";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";  // prints in ascending order
        minPQ.pop();
    }
    cout << endl;

    // Custom comparator for user defined types
    priority_queue<Person, vector<Person>, Comparator> pq;
    pq.push(Person("Alice", 30));
    pq.push(Person("Bob", 25));
    pq.push(Person("Charlie", 35));

    cout << "\nPersons in ascending order of age:\n";
    while (!pq.empty()) {
        Person p = pq.top();
        cout << p.name << " (" << p.age << ")\n";
        pq.pop();
    }

    return 0;
}