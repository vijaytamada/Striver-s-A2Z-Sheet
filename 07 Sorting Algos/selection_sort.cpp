/*
    ============================================================
    TOPIC   : Sorting Algos
    PROBLEM : Selection Sort
    ============================================================

    INTUITION:
    ----------
    - Repeatedly find the smallest element in the unsorted remainder of
      the array and swap it into its correct position at the front.
    - Unlike bubble/insertion sort, selection sort does the minimum
      number of swaps (exactly one per pass), but still scans the whole
      unsorted part every time to find the minimum.

    STEPS:
    ----------
    1. Loop i from 0 to n-2 (the boundary of the sorted/unsorted split).
    2. Inner loop j from i+1 to n-1: find the index of the smallest
       element in arr[i..n-1], track it as minIdx.
    3. Swap arr[i] with arr[minIdx] to place the minimum at position i.

    VARIATIONS TO REMEMBER:
    ----------
    - NOT stable by default (swapping can reorder equal elements) - unlike
      bubble/insertion sort.
    - In-place, and always exactly n-1 swaps regardless of input order -
      good when swap cost is high but comparison cost is low.
    - No early-exit optimization possible - always does the full O(n^2)
      comparisons even if the array is already sorted.

    TIME COMPLEXITY  : O(n^2) -> nested loops always run fully, regardless of input order
    SPACE COMPLEXITY : O(1) -> sorts in-place, no extra array
    ============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// Selection Sort: sorts the array in ascending order
void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        // Find the index of the smallest element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // Swap the found minimum with the current element
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    selectionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}