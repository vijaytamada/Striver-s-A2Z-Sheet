/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Input / Output
    ============================================================

    WHAT & WHY:
    ----------
    - `cin` reads input from the keyboard, `cout` writes output to the console.
    - `<iomanip>` gives formatting helpers to control how numbers are displayed.

    KEY POINTS:
    ----------
    1. `cin >> var` reads until the next whitespace (spaces/newlines stop it).
    2. `getline(cin, str)` reads a full line, including spaces.
    3. `fixed << setprecision(n)` prints floating point numbers with n digits
       after the decimal point.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Mixing `cin >>` and `getline` can leave a leftover newline in the buffer,
      causing the next `getline` to read an empty line.
    - `cin >> name` won't capture names with spaces — use `getline` for that.
    ============================================================
*/
#include <iomanip>  // for setw, setprecision
#include <iostream>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;  // takes input until the first whitespace
    // getline(cin, name); // to take full line input including spaces
    
    cout << "Enter your age: ";
    cin >> age;

    cout << "Name: " << name << ", Age: " << age << endl;

    double value = 3.14159;
    cout << "Formatted value: " << fixed << setprecision(2) << value << endl;
    return 0;
}
