/*
    ============================================================
    TOPIC   : Sorting Algos
    PROBLEM : Merge Sort (version 2 - single shared temp array)
    ============================================================

    INTUITION:
    ----------
    - Same divide-and-conquer idea as merge_sort_1.cpp: split into halves,
      sort each half, merge them back in sorted order using two pointers.
    - Optimization here: instead of allocating new left/right vectors on
      every merge call, one "temp" array (same size as arr) is created
      once and reused/passed through all recursive calls.

    STEPS:
    ----------
    1. mergeSort(arr, start, end, temp): base case start >= end.
    2. Find mid, recursively sort left [start, mid] and right [mid+1, end],
       passing the same temp array down.
    3. merge(): use two pointers i (left half) and j (right half) to write
       the smaller element into temp[k] each step; copy any leftovers;
       then copy the merged [start, end] range from temp back into arr.

    VARIATIONS TO REMEMBER:
    ----------
    - merge_sort_1.cpp allocates new arrays per merge call - this version
      avoids that repeated allocation, which matters for performance on
      large inputs.
    - Still stable and O(n log n) - the optimization is about constant
      factors (fewer allocations), not asymptotic complexity.

    TIME COMPLEXITY  : O(n log n) -> log n levels of splitting, O(n) merge work per level
    SPACE COMPLEXITY : O(n) -> one shared temp array (plus recursion stack)
    ============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end, vector<int> &temp) {
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= end)
        temp[k++] = arr[j++];

    // Copy merged part back to arr
    for (int idx = start; idx <= end; ++idx)
        arr[idx] = temp[idx];
}

void mergeSort(vector<int> &arr, int start, int end, vector<int> &temp) {
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid, temp);
    mergeSort(arr, mid + 1, end, temp);
    merge(arr, start, mid, end, temp);
}

int main() {
    vector<int> arr = {4, 7, 1, 2, 9, 0};
    vector<int> temp(arr.size());

    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1, temp);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
