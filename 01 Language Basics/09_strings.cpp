/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Strings
    ============================================================

    WHAT & WHY:
    ----------
    - `std::string` is a resizable sequence of characters with lots of built-in
      helper functions (unlike plain C-style char arrays).
    - Covers common string operations you'll use constantly in DSA problems.

    KEY POINTS:
    ----------
    1. `size()`/`length()`, `front()`/`back()`, `substr(pos, len)`, `find(...)`.
    2. `insert`, `append`, `erase`, `replace`, `push_back`, `pop_back` all modify
       the string in place.
    3. `<cctype>` functions (`isalpha`, `isdigit`, `isspace`, `toupper`, `tolower`)
       work on single characters. `stoi`/`stof`/`to_string` convert string <-> number.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - `find()` returns `string::npos` (not -1) when nothing is found.
    - `tolower`/`toupper` return an `int`, so cast back to `char` when printing.
    ============================================================
*/
#include <cctype>  // For character functions like isalpha, isdigit
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello123 World! ";

    // String basic info
    cout << "Original string: " << s << endl;
    cout << "Length: " << s.size() << endl;
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << endl;
    cout << "First character: " << s.front() << endl;
    cout << "Last character: " << s.back() << endl;

    // Substring and finding
    cout << "Substring (0,5): " << s.substr(0, 5) << endl;
    cout << "Find 'World': " << s.find("World") << endl;
    cout << "Find last of 'lo': " << s.find_last_of("lo") << endl;

    // Insert, append, erase, replace
    s.insert(5, " INSERTED ");
    cout << "After insert: " << s << endl;
    s.append(" APPEND");
    cout << "After append: " << s << endl;
    s.erase(5, 9);
    cout << "After erase: " << s << endl;
    s.replace(0, 5, "Hi");
    cout << "After replace: " << s << endl;

    // Push back and pop back
    s.push_back('!');
    cout << "After push_back: " << s << endl;
    s.pop_back();
    cout << "After pop_back: " << s << endl;

    // Character functions on example characters
    char ch1 = 'A', ch2 = '9', ch3 = ' ';
    cout << "Character checks:" << endl;
    cout << ch1 << " isalpha? " << isalpha(ch1) << endl;
    cout << ch2 << " isdigit? " << isdigit(ch2) << endl;
    cout << ch3 << " isspace? " << isspace(ch3) << endl;
    cout << ch1 << " tolower: " << (char)tolower(ch1) << endl;
    cout << ch2 << " toupper: " << (char)toupper(ch2) << endl;

    // String to number & number to string conversions
    string numStr = "12345";
    int num = stoi(numStr);
    cout << "String to int: " << num << endl;
    float fnum = stof("12.34");
    cout << "String to float: " << fnum << endl;
    string s2 = to_string(9876);
    cout << "Number to string: " << s2 << endl;

    return 0;
}
