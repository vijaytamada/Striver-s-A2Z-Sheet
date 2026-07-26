/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Linear Search
    ============================================================

    INTUITION:
    ----------
    - Simplest possible search: check every element one by one until
      the target is found. No assumption about the array being sorted.

    STEPS:
    ----------
    1. Loop through each index i from 0 to n-1.
    2. If arr[i] == target, return i immediately.
    3. If loop finishes without a match, return -1.

    VARIATIONS TO REMEMBER:
    ----------
    - If array is sorted, use binary search instead -> O(log n).
    - Base case for many "find index of X" style problems.

    TIME COMPLEXITY  : O(n) -> may need to check every element
    SPACE COMPLEXITY : O(1) -> no extra space used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target)
            return i;  // Return the index if the target is found
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    vector<int> arr = {4, 2, 3, 1, 5};
    int target = 3;

    int result = linearSearch(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}