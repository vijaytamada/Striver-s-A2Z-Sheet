/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Rotate Array by K places
    ============================================================

    INTUITION:
    ----------
    - Every element at index i should end up at index (i + k) % n after
      rotating right by k. That formula alone solves the whole problem.
    - Implemented here using an extra array to directly place each
      element at its final position.

    STEPS:
    ----------
    1. Create a result array of the same size, initialized to 0.
    2. For each i, place nums[i] at res[(i + k) % n].
    3. Copy res back into nums.

    VARIATIONS TO REMEMBER:
    ----------
    - True O(1) space trick: reverse the whole array, then reverse first
      k elements, then reverse the remaining n-k elements.
    - Naive shift-one-by-one approach is O(n*k) time, O(1) space - too
      slow for large k, shown here only as a comment for reference.

    TIME COMPLEXITY  : O(n) -> single pass to place each element
    SPACE COMPLEXITY : O(n) -> extra array used to hold rotated result
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Soln 1 - shift elements one by one
// T.C = O(n*k) , S.C = O(1)

// Soln 2 - Using extra array
// T.C = O(n) , S.C = O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < n; i++) {
            res[(i + k) % n] = nums[i];
        }
        nums = res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    sol.rotate(arr, k);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}