/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Find the Missing Number in an Array (1 to N)
    ============================================================

    INTUITION:
    ----------
    - If array has n numbers taken from 1..n (or 0..n) with exactly one
      missing, the sum of 1..n minus the actual sum of the array gives
      the missing number directly.
    - No need to sort or use extra space.

    STEPS:
    ----------
    1. Compute expected sum = n*(n+1)/2.
    2. Compute actual sum of all elements in nums.
    3. Missing number = expected sum - actual sum.

    VARIATIONS TO REMEMBER:
    ----------
    - Can also solve using XOR of all numbers 1..n XOR all array elements
      (avoids overflow for very large n).
    - If TWO numbers are missing/repeating, see find_repeating_and_missing.cpp.

    TIME COMPLEXITY  : O(n) -> single pass to sum the array
    SPACE COMPLEXITY : O(1) -> only a couple of variables used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (auto it : nums)
            sum += it;

        return (n * (n + 1)) / 2 - sum;
    }
};

int main() {
    return 0;
}