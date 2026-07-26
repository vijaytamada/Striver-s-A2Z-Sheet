/*
    ============================================================
    TOPIC   : Language Basics
    CONCEPT : Arrays
    ============================================================

    WHAT & WHY:
    ----------
    - An array stores multiple values of the same type in one contiguous block
      of memory, accessed by index.
    - Foundation for almost every DSA problem — needed before lists/vectors.

    KEY POINTS:
    ----------
    1. Indexing starts at 0; last valid index is `size - 1`.
    2. `sizeof(arr) / sizeof(arr[0])` gives the number of elements (only works
       on a real array, not a decayed pointer).
    3. Array size is fixed at compile time (for a plain C-style array).

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Accessing out-of-bounds indices doesn't crash immediately — it's undefined
      behavior and can silently corrupt memory.
    - Passing an array to a function decays it to a pointer, so `sizeof` trick
      won't work inside that function.
    ============================================================
*/
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {2, 4, 6, 8, 10};
    
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array elements are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
    cout << "\nArray size is: " << size << endl;

    return 0;
}
