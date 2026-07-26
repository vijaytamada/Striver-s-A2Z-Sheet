/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : Count Inversions (pairs i < j where arr[i] > arr[j])
    ============================================================

    INTUITION:
    ----------
    - Brute force: check every pair with two nested loops, O(n^2).
    - Optimal: piggyback on merge sort. While merging two already-sorted
      halves, whenever we pick an element from the right half BEFORE
      an element from the left half, it means that right-half element is
      smaller than ALL remaining elements in the left half - so we can
      count (mid - i) inversions in one shot instead of comparing one by one.

    STEPS (Merge Sort based):
    ----------
    1. Recursively mergeSort the left half and right half, summing up
       inversions found in each.
    2. During the merge step: use pointers i (left half) and j (right half).
       If arr[i] <= arr[j], take arr[i] (no inversion). Otherwise take
       arr[j] and add (mid - i) to inversion count, since arr[i..mid-1]
       are all greater than arr[j].
    3. Copy remaining elements, add merge-step inversions to the total.

    VARIATIONS TO REMEMBER:
    ----------
    - Reverse Pairs (arr[i] > 2*arr[j]) -> same merge sort trick but with a
      different comparison, needs a separate counting pass before merging
      (see reverse_pairs.cpp).
    - Count of smaller elements after self -> similar merge-sort-based counting.

    TIME COMPLEXITY  : O(n log n) -> standard merge sort recurrence (brute force is O(n^2))
    SPACE COMPLEXITY : O(n) -> temp array used during merge
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution1 {
public:
    int inversionCount(vector<int>& arr) {
        // Code Here
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] > arr[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

// Optimal Approach using Merge Sort
class Solution {
public:
    int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int i = left, j = mid, k = left;
        int inv_count = 0;

        while (i < mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv_count += (mid - i);  // All remaining elements in left half are greater
            }
        }

        while (i < mid)
            temp[k++] = arr[i++];
        while (j <= right)
            temp[k++] = arr[j++];

        for (int idx = left; idx <= right; ++idx) {
            arr[idx] = temp[idx];
        }

        return inv_count;
    }

    int mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
        int inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            inv_count += mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid + 1, right);
            inv_count += merge(arr, temp, left, mid + 1, right);
        }
        return inv_count;
    }

    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n);
        return mergeSort(arr, temp, 0, n - 1);
    }
};

int main() {
    return 0;
}