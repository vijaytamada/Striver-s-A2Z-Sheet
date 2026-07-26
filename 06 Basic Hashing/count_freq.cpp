/*
    ============================================================
    TOPIC   : Basic Hashing
    PROBLEM : Count Frequency of Elements in an Array
    ============================================================

    INTUITION:
    ----------
    - A hash map lets you count occurrences of each value in a single
      pass, without needing the array to be sorted or bounded in range.

    STEPS:
    ----------
    1. Create an unordered_map<int, int> to hold value -> frequency.
    2. Loop through the array; for each element, increment its count in
       the map (freq[num]++ auto-inserts with default 0 the first time).
    3. Iterate over the map to print each element's frequency.

    VARIATIONS TO REMEMBER:
    ----------
    - If values are small and bounded (e.g. 0-255), a plain array/vector
      as a "counting array" is faster than a hash map (no hashing overhead).
    - Same pattern is the basis for "most frequent element"
      (max_occuring_element.cpp) and majority element problems.

    TIME COMPLEXITY  : O(n) -> single pass to build map, O(1) avg per insert
    SPACE COMPLEXITY : O(n) -> up to n distinct keys stored in the map
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5};
    unordered_map<int, int> freq;

    for (int num : arr) {
        freq[num]++;
    }

    cout << "Element Frequencies:\n";
    for (auto &it : freq) {
        cout << it.first << ": " << it.second << endl;
    }

    return 0;
}