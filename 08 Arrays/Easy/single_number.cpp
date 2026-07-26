/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Single Number (every element appears twice except one)
    ============================================================

    INTUITION:
    ----------
    - XOR trick: a ^ a = 0 for any number, and a ^ 0 = a.
    - So if we XOR every element together, all the pairs cancel out to 0,
      and only the single unpaired number survives.

    STEPS:
    ----------
    1. xorr = 0.
    2. XOR every element of nums into xorr.
    3. Return xorr (whatever's left after all pairs cancel).

    VARIATIONS TO REMEMBER:
    ----------
    - "Single Number II" (every element appears 3 times except one) needs
      bit counting instead of plain XOR.
    - "Single Number III" (two unique numbers, rest appear twice) - XOR all,
      then split based on a set bit to separate the two uniques.

    TIME COMPLEXITY  : O(n) -> single pass, XOR-ing each element
    SPACE COMPLEXITY : O(1) -> only one variable used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;

        for (auto it : nums)
            xorr = xorr ^ it;

        return xorr;
    }
};

int main() {
    return 0;
}