/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Union of Two Sorted Arrays
    ============================================================

    INTUITION:
    ----------
    - Since both arrays are already sorted, use the classic merge-step
      from merge sort: walk both with two pointers, always take the
      smaller element.
    - To avoid duplicates in the result, only push a value if it's
      different from the last value already pushed into res.

    STEPS:
    ----------
    1. idx1 = idx2 = 0.
    2. While both pointers are in range, compare arr1[idx1] vs arr2[idx2],
       push the smaller one (skip if same as res.back()), advance that pointer.
    3. Once one array is exhausted, push all remaining elements from the
       other array (again skipping duplicates against res.back()).
    4. Return res.

    VARIATIONS TO REMEMBER:
    ----------
    - Intersection of two sorted arrays -> similar two-pointer merge but
      only push when arr1[idx1] == arr2[idx2].
    - If arrays are unsorted, use a hash set instead (O(n+m) but no order
      guarantee without extra sorting).

    TIME COMPLEXITY  : O(n + m) -> single pass through both arrays combined
    SPACE COMPLEXITY : O(n + m) -> result array can hold up to that many elements
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> unionOfArrays(vector<int> &arr1, vector<int> &arr2) {
    vector<int> res;

    int idx1 = 0;
    int idx2 = 0;

    while (idx1 < arr1.size() && idx2 < arr2.size()) {
        if (arr1[idx1] < arr2[idx2]) {
            if (res.size() == 0 || res.back() != arr1[idx1]) {
                res.push_back(arr1[idx1]);
            }
            idx1++;
        } else {
            if (res.size() == 0 || res.back() != arr2[idx2]) {
                res.push_back(arr2[idx2]);
            }
            idx2++;
        }
    }

    while (idx1 < arr1.size()) {
        if (res.size() == 0 || res.back() != arr1[idx1]) {
            res.push_back(arr1[idx1]);
        }
        idx1++;
    }

    while (idx2 < arr2.size()) {
        if (res.size() == 0 || res.back() != arr2[idx2]) {
            res.push_back(arr2[idx2]);
        }
        idx2++;
    }

    return res;
}

int main() {
    vector<int> arr1 = {1, 2, 4, 5, 6};
    vector<int> arr2 = {2, 3, 5, 7};

    vector<int> result = unionOfArrays(arr1, arr2);

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}