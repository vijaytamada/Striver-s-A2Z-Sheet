/*
    ============================================================
    TOPIC   : Sorting Algos
    PROBLEM : Bubble Sort
    ============================================================

    INTUITION:
    ----------
    - Repeatedly compare adjacent elements and swap them if they're in the
      wrong order. Each full pass "bubbles" the largest remaining element
      to its correct position at the end.
    - If a full pass makes zero swaps, the array is already sorted - stop
      early.

    STEPS:
    ----------
    1. Loop i from 0 to n-2 (number of passes needed).
    2. Inner loop j from 0 to n-i-2: compare arr[j] and arr[j+1], swap if
       arr[j] > arr[j+1].
    3. Track a "swapped" flag; if no swap happened in a pass, break early
       (already sorted).

    VARIATIONS TO REMEMBER:
    ----------
    - Stable (equal elements keep relative order) and in-place (no extra
      array needed).
    - Best case (already sorted) is O(n) thanks to the early-exit flag;
      without it, bubble sort is always O(n^2).

    TIME COMPLEXITY  : O(n^2) worst/avg -> nested loops; O(n) best case with early exit
    SPACE COMPLEXITY : O(1) -> sorts in-place, no extra array
    ============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort: sorts the array in ascending order
void bubbleSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        // After each pass, the largest element moves to the end
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps occurred, the array is already sorted
        if (!swapped)
            break;
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}