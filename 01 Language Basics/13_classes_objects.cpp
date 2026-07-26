/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Classes and Objects
    ============================================================

    WHAT & WHY:
    ----------
    - A class bundles data (members) and behavior (methods) together — the
      basis of object-oriented programming.
    - Members default to `private` here, so `width`/`height` can only be set
      through the constructor, not directly from outside.

    KEY POINTS:
    ----------
    1. A constructor (same name as class) runs automatically when an object
       is created, to set up initial state.
    2. `object.method()` for a normal object, `pointer->method()` for a pointer to one.
    3. `public:` marks what's accessible from outside the class.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Trying to access private members directly from outside the class (compile error).
    - Forgetting to `delete` objects created with `new` (memory leak).
    ============================================================
*/
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
public:
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }
    int area() {
        return width * height;
    }
};

int main() {
    Rectangle r(4, 6);
    cout << "Area using constructor: " << r.area() << endl;

    Rectangle *p1 = new Rectangle(5, 10);
    cout << "Area using pointer: " << p1->area() << endl;

    return 0;
}
