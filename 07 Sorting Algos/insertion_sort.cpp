/*
    ============================================================
    TOPIC   : Sorting Algos
    PROBLEM : Insertion Sort
    ============================================================

    INTUITION:
    ----------
    - Think of sorting playing cards in your hand: take the next card
      (element), and shift it backward past all larger cards already
      sorted, dropping it into its correct spot.
    - The left part of the array is always kept sorted as you go.

    STEPS:
    ----------
    1. Loop i from 1 to n-1, treating arr[i] as the "current" element to
       place correctly.
    2. Shift all elements greater than curr one position to the right
       (inner while loop, moving j backward).
    3. Drop curr into the gap left behind (arr[j] = curr).

    VARIATIONS TO REMEMBER:
    ----------
    - Stable and in-place, like bubble sort, but generally fewer
      comparisons in practice - efficient for nearly-sorted or small arrays.
    - Best case (already sorted) is O(n) since the inner while loop barely runs.

    TIME COMPLEXITY  : O(n^2) worst/avg -> shifting elements for each insertion
    SPACE COMPLEXITY : O(1) -> sorts in-place, no extra array
    ============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// Insertion Sort: sorts the array in ascending order
void insertionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int j = i;

        // Shift elements greater than curr to the right
        while (j >= 0 && arr[j-1] > curr) {
            arr[j] = arr[j-1];
            j--;
        }

        // Place curr in its correct position
        arr[j] = curr;
    }
}

int main() {
    vector<int> arr = {4, 7, 1, 2, 9, 0};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    insertionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}