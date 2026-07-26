/*
    ============================================================
    TOPIC   : Sorting Algos
    PROBLEM : Merge Sort (version 1 - allocates new left/right arrays per merge)
    ============================================================

    INTUITION:
    ----------
    - Divide and conquer: split the array into halves recursively until
      each piece has 1 element (trivially sorted), then merge sorted
      halves back together in order.
    - The merge step is the key trick: walk two sorted halves with two
      pointers, always picking the smaller front element.

    STEPS:
    ----------
    1. mergeSort(arr, start, end): base case start >= end (0 or 1
       elements, already sorted).
    2. Find mid, recursively sort the left half [start, mid] and right
       half [mid+1, end].
    3. merge(): copy the two halves into temporary "left" and "right"
       vectors, then merge them back into arr in sorted order using two
       pointers, followed by copying any leftover elements.

    VARIATIONS TO REMEMBER:
    ----------
    - This version allocates fresh left/right vectors on EVERY merge call -
      simple to understand but does more allocations.
    - merge_sort_2.cpp is the optimized version using a single shared temp
      array instead - same algorithm, less allocation overhead.
    - Stable sort (equal elements keep relative order), unlike quick sort.

    TIME COMPLEXITY  : O(n log n) -> log n levels of splitting, O(n) merge work per level
    SPACE COMPLEXITY : O(n) -> temporary arrays used during merge (plus recursion stack)
    ============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// Merges two sorted halves of the array
void merge(vector<int> &arr, int start, int mid, int end) {
    int l1 = mid - start + 1;
    int l2 = end - mid;

    vector<int> left(l1);
    vector<int> right(l2);

    int idx = 0;
    for (int i = start; i <= mid; ++i)
        left[idx++] = arr[i];

    idx = 0;
    for (int i = mid + 1; i <= end; ++i)
        right[idx++] = arr[i];

    int idx1 = 0;
    int idx2 = 0;
    idx = start;

    // Merge the two halves
    while (idx1 < l1 && idx2 < l2) {
        if (left[idx1] <= right[idx2])
            arr[idx++] = left[idx1++];
        else
            arr[idx++] = right[idx2++];
    }

    // Copy remaining elements
    while (idx1 < l1)
        arr[idx++] = left[idx1++];

    while (idx2 < l2)
        arr[idx++] = right[idx2++];
}

// Recursively sorts the array using merge sort
void mergeSort(vector<int> &arr, int start, int end) {
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main() {
    vector<int> arr = {4, 7, 1, 2, 9, 0};

    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}