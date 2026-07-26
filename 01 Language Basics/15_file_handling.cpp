/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : File Handling
    ============================================================

    WHAT & WHY:
    ----------
    - File handling lets a program read from and write to files on disk, so
      data can persist beyond a single run of the program.
    - Done using stream classes from `<fstream>`.

    KEY POINTS:
    ----------
    1. `ofstream` = output file stream (writing to a file).
       `ifstream` = input file stream (reading from a file).
       `fstream` = can do both.
    2. Always check `if (file.is_open())` before reading/writing.
    3. Close the file with `file.close()` when done (or let the destructor do it
       automatically when it goes out of scope).

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Forgetting to check whether the file actually opened (wrong path, permissions).
    - Not closing the file, which can leave data unflushed/unwritten to disk.
    - Opening with `ofstream` (not `ios::app`) truncates/overwrites existing content.
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. Writing to a file (creates it if it doesn't exist, overwrites if it does)
    ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << "Hello, File Handling in C++!" << endl;
        outFile << "This is the second line." << endl;
        outFile.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }

    // 2. Reading from a file line by line
    ifstream inFile("example.txt");
    if (inFile.is_open()) {
        string line;
        cout << "--- File contents ---" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }

    // 3. Appending to a file (ios::app keeps existing content, adds at the end)
    ofstream appendFile("example.txt", ios::app);
    if (appendFile.is_open()) {
        appendFile << "This line was appended." << endl;
        appendFile.close();
    }

    // 4. fstream can both read and write with the same stream object
    fstream file("example.txt", ios::in | ios::out);
    if (file.is_open()) {
        string line;
        cout << "--- Re-reading after append ---" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    return 0;
}
