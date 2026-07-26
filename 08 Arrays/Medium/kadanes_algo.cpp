/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Kadane's Algorithm - Maximum Subarray Sum
    ============================================================

    INTUITION:
    ----------
    - We want the max sum of any contiguous subarray.
    - Keep a running sum while walking the array. If that running sum ever
      goes negative, it can only hurt any future subarray, so drop it and
      restart from 0 - a negative prefix is never worth carrying forward.
    - Track the best sum seen so far separately.

    STEPS:
    ----------
    1. currentSum = 0, maxSum = INT_MIN.
    2. For each element: currentSum += element.
    3. maxSum = max(maxSum, currentSum).
    4. If currentSum < 0, reset currentSum = 0.
    5. Return maxSum.

    VARIATIONS TO REMEMBER:
    ----------
    - Print the actual subarray: track start/end indices when maxSum updates.
    - Max product subarray: track both running max AND running min (a negative
      times a negative can flip the sign and become the new max).
    - Circular array max subarray = max(normal Kadane, totalSum - minSubarray).

    TIME COMPLEXITY  : O(n) -> single pass over the array
    SPACE COMPLEXITY : O(1) -> only a few variables used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for (int& it : nums) {
            currSum += it;
            maxSum = max(maxSum, currSum);

            if (currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;
    }
};

int main() {
    return 0;
}