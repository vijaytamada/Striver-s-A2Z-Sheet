/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : string, Character Functions, and C-style Strings
    ============================================================

    WHAT & WHY:
    ----------
    - std::string is a dynamic, resizable character sequence with built-in
      operations (concat, substr, find, replace) - avoids manual char[]
      handling for most tasks.
    - <cctype> gives per-character checks/conversions; <cstring> covers
      old-style char[] strings you'll still see in legacy/C-style code.

    KEY POINTS:
    ----------
    1. Concatenation (+) and substr(pos, len) -> both O(n) (new string built).
    2. find(sub) -> O(n*m) worst case, returns index or string::npos if
       not found.
    3. insert/erase/replace -> O(n) due to shifting characters.
    4. toupper/tolower/isdigit/isalpha/isalnum/isspace -> O(1) per char,
       operate on a single char and return an int (cast to char if printing).
    5. C-style: strlen, strcmp, strcat operate on '\0'-terminated char
       arrays, not std::string.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - find() returns string::npos (a huge unsigned value) when not found -
      never treat it as -1 directly without comparing to npos.
    - strcat() (and other C-string functions) do NOT bounds-check - writing
      past the destination buffer is undefined behavior (used here for
      demo only, avoid in real code; prefer std::string).
    ============================================================
*/

#include <iostream>
#include <string>
#include <cctype>   // for character functions
#include <cstring>  // for C-style string functions
using namespace std;

int main() {
    // --- STRING INITIALIZATION ---
    string s1;                       // empty string
    string s2 = "Hello";             // direct initialization
    string s3("World");              // constructor style
    string s4 = s2 + " " + s3;       // concatenation
    string s5 = s4.substr(0, 5);     // substring

    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4 (concat): " << s4 << endl;
    cout << "s5 (substr): " << s5 << endl;

    // --- STRING OPERATIONS ---
    cout << "\nString operations:\n";
    cout << "Length of s4: " << s4.length() << endl;
    cout << "Find 'World' in s4: " << s4.find("World") << endl;
    cout << "Replace 'World' with 'Vijay': " << s4.replace(6, 5, "Vijay") << endl;
    cout << "After erase: " << s4.erase(0, 6) << endl;
    s4.insert(0, "Hi ");
    cout << "After insert: " << s4 << endl;
    s2.pop_back();
    cout << "After pop_back on s2: " << s2 << endl;
    s2 += 'a';
    cout << "After += 'a' on s2: " << s2 << endl;


    // --- CHARACTER FUNCTIONS ---
    char ch = 'a';
    cout << "\nCharacter functions:\n";
    cout << "Original char: " << ch << endl;
    cout << "toupper: " << char(toupper(ch)) << endl;
    cout << "tolower: " << char(tolower('Z')) << endl;
    cout << "isdigit('5'): " << isdigit('5') << endl;
    cout << "isalpha('@'): " << isalpha('@') << endl;
    cout << "isalnum('A'): " << isalnum('A') << endl;
    cout << "isspace(' '): " << isspace(' ') << endl;

    // --- C-STYLE STRING FUNCTIONS ---
    char cstr1[] = "Vijay";
    char cstr2[] = "DSA";
    cout << "\nC-style string functions:\n";
    cout << "strlen(cstr1): " << strlen(cstr1) << endl;
    cout << "strcmp(cstr1, cstr2): " << strcmp(cstr1, cstr2) << endl;
    strcat(cstr1, cstr2); // unsafe, for demo only
    cout << "After strcat: " << cstr1 << endl;

    return 0;
}