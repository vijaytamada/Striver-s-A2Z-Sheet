/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Largest Element in an Array
    ============================================================

    INTUITION:
    ----------
    - Just walk through the array once, keeping track of the biggest
      value seen so far.

    STEPS:
    ----------
    1. Start maxEle = arr[0].
    2. For every element, if it's bigger than maxEle, update maxEle.
    3. Return maxEle after the loop ends.

    VARIATIONS TO REMEMBER:
    ----------
    - Can also just use *max_element(arr.begin(), arr.end()) (STL one-liner).
    - See second_largest_element.cpp for the natural follow-up question.

    TIME COMPLEXITY  : O(n) -> single pass over the array
    SPACE COMPLEXITY : O(1) -> only one variable used to track max
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr) {
    int maxEle = arr[0];
    for (int &it : arr) {
        if (it > maxEle) {
            maxEle = it;
        }
    }
    return maxEle;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int largest = largestElement(arr);
    cout << "Largest element: " << largest << endl;

    // one liner
    cout << "Largest element (one liner): " << *max_element(arr.begin(), arr.end()) << endl;

    return 0;
}