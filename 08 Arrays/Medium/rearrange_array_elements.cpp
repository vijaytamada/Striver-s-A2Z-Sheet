/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Rearrange Array Elements by Sign (equal +ve and -ve counts)
    ============================================================

    INTUITION:
    ----------
    - Array has equal number of positive and negative numbers, and we need
      to rearrange them alternately starting with positive, while keeping
      the relative order within each sign group.
    - Use two separate index pointers for the result array: one for even
      positions (0, 2, 4...) for positives, one for odd positions (1, 3, 5...)
      for negatives. Fill them in as we scan the original array once.

    STEPS:
    ----------
    1. posIdx = 0, negIdx = 1.
    2. For each element in nums: if positive, place it at res[posIdx],
       posIdx += 2. If negative, place at res[negIdx], negIdx += 2.
    3. Return res.

    VARIATIONS TO REMEMBER:
    ----------
    - Unequal count of positives/negatives -> fill alternately as long as
      possible, then append the leftover elements of the longer group at
      the end (in order).

    TIME COMPLEXITY  : O(n) -> single pass over the array
    SPACE COMPLEXITY : O(n) -> separate result array used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        int posIdx = 0;
        int negIdx = 1;

        for (int& it : nums) {
            if (it > 0) {
                res[posIdx] = it;
                posIdx += 2;
            } else {
                res[negIdx] = it;
                negIdx += 2;
            }
        }

        return res;
    }
};

int main() {
    return 0;
}