/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : Longest Subarray with Sum 0
    ============================================================

    INTUITION:
    ----------
    - This is just "longest subarray with sum k" with k = 0.
    - Track prefix sum as we scan. If the SAME prefix sum repeats at two
      different indices, the subarray between them sums to 0 (since
      whatever was added in between canceled out).
    - Store only the FIRST occurrence index of each prefix sum, so any
      later match gives the longest possible subarray.
    - Special case: if prefixSum itself becomes 0 at index i, the whole
      subarray from 0 to i sums to 0.

    STEPS:
    ----------
    1. prefixSum = 0, maxLength = 0, empty hashmap.
    2. For each index i, add arr[i] to prefixSum.
    3. If prefixSum == 0, maxLength = i + 1 (whole prefix sums to zero).
    4. Else if prefixSum was seen before at index j, maxLength =
       max(maxLength, i - j).
    5. Else store this prefixSum -> i in the map (first occurrence only).

    VARIATIONS TO REMEMBER:
    ----------
    - General "longest subarray with sum k" -> same hashmap pattern, see
      longest_subarray_with_sum_k_with_negatives.cpp.
    - Count of subarrays with sum k -> count frequency instead of storing
      first index, see subarrays_sum_equals_k.cpp.

    TIME COMPLEXITY  : O(n) -> single pass with hashmap lookups
    SPACE COMPLEXITY : O(n) -> hashmap can store up to n prefix sums
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> prefixSumIndex;
        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < arr.size(); ++i) {
            prefixSum += arr[i];

            if (prefixSum == 0) {
                maxLength = i + 1;
            } else {
                if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()) {
                    maxLength = max(maxLength, i - prefixSumIndex[prefixSum]);
                } else {
                    prefixSumIndex[prefixSum] = i;
                }
            }
        }

        return maxLength;
    }
};

int main() {
    return 0;
}