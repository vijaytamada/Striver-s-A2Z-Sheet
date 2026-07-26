/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Structures
    ============================================================

    WHAT & WHY:
    ----------
    - A `struct` groups related variables (of possibly different types) under
      one custom type — useful for modeling real-world entities like a Person.
    - Members default to `public` (unlike a class, where they default to `private`).

    KEY POINTS:
    ----------
    1. Access members with `.` for a normal object, `->` for a pointer to the struct.
    2. Can be initialized with brace initialization: `{value1, value2, ...}`.
    3. `new Person` allocates a struct on the heap — must eventually `delete` it.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Forgetting `->` when accessing members through a pointer (mixing it with `.`).
    - Memory leak if a heap-allocated struct (via `new`) is never `delete`d.
    ============================================================
*/
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    Person p1 = {"Alice", 25};
    cout << "Name: " << p1.name << ", Age: " << p1.age << endl;

    // modify
    p1.age = 26;
    cout << "Updated Age: " << p1.age << endl;

    Person *p2 = new Person;
    p2->name = "Bob";
    p2->age = 30;

    return 0;
}
