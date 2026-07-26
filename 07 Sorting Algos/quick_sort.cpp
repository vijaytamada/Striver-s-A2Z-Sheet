/*
    ============================================================
    TOPIC   : Sorting Algos
    PROBLEM : Quick Sort
    ============================================================

    INTUITION:
    ----------
    - Pick a pivot (here, the first element), then rearrange the array so
      everything smaller than the pivot ends up on its left, everything
      bigger on its right (the "partition" step). The pivot is now in its
      final sorted position.
    - Recursively apply the same process to the left and right sub-arrays.

    STEPS:
    ----------
    1. partition(): pivot = arr[start]. Use two pointers "left" (from
       start+1) and "right" (from end) that move toward each other,
       skipping elements already on the correct side; swap when
       left finds something >= pivot and right finds something <= pivot.
    2. When left and right cross, swap pivot (arr[start]) with arr[right]
       to drop the pivot into its correct sorted position.
    3. quickSort(): recursively sort the sub-array left of the pivot and
       the sub-array right of the pivot.

    VARIATIONS TO REMEMBER:
    ----------
    - Not stable (equal elements can get reordered), unlike merge sort.
    - In-place (no extra array like merge sort needs) - a key advantage.
    - Worst case O(n^2) happens on already-sorted/reverse-sorted input
      with this "always pick first element" pivot strategy; randomized or
      median-of-three pivot selection avoids that.

    TIME COMPLEXITY  : O(n log n) average -> balanced partitions; O(n^2) worst case -> unbalanced partitions
    SPACE COMPLEXITY : O(log n) average recursion stack -> O(n) worst case for skewed partitions
    ============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// Partitions the array around a pivot and returns its final position
int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[start];
    int left = start + 1;
    int right = end;

    while (left <= right) {
        while (left <= end && arr[left] <= pivot)
            left++;
        while (right >= start + 1 && arr[right] > pivot)
            right--;

        if (left < right)
            swap(arr[left], arr[right]);
    }

    swap(arr[start], arr[right]);  // Place pivot in correct position
    return right;
}

// Recursively sorts the array using Quick Sort
void quickSort(vector<int> &arr, int start, int end) {
    if (start >= end)
        return;

    int pivotIndex = partition(arr, start, end);
    quickSort(arr, start, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, end);
}

int main() {
    vector<int> arr = {4, 7, 1, 2, 9, 0};

    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}