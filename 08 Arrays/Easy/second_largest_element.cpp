/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Second Largest Element in an Array (without sorting)
    ============================================================

    INTUITION:
    ----------
    - Track the largest (max1) and second largest (max2) in a single pass.
    - Whenever a bigger element than max1 shows up, the old max1 becomes
      the new max2 before max1 gets updated.
    - Careful with duplicates: only update max2 if the value is strictly
      less than max1 (so a repeated max value doesn't count as "second largest").

    STEPS:
    ----------
    1. max1 = max2 = INT_MIN.
    2. For each element: if it > max1, then max2 = max1, max1 = element.
    3. Else if it > max2 AND it != max1, then max2 = element.
    4. Return max2.

    VARIATIONS TO REMEMBER:
    ----------
    - Sorting approach is simpler (O(n log n)) but this one-pass method is
      the optimal O(n) way interviewers expect.
    - Same idea extends to "kth largest" using a min-heap of size k.

    TIME COMPLEXITY  : O(n) -> single pass over the array
    SPACE COMPLEXITY : O(1) -> only two tracking variables used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int> &arr) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;

    for (int &it : arr) {
        if (it > max1) {
            max2 = max1;
            max1 = it;
        } else if (it > max2 && it != max1) {
            max2 = it;
        }
    }

    return max2;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int secondLargest = secondLargestElement(arr);
    cout << "Second largest element: " << secondLargest << endl;
    return 0;
}