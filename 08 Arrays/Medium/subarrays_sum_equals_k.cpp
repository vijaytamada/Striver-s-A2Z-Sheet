/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Subarray Sum Equals K (count of subarrays, array can have negatives)
    ============================================================

    INTUITION:
    ----------
    - We want the COUNT of subarrays summing to k, not just the longest one.
    - Use prefix sums + hashmap storing FREQUENCY of each prefix sum seen
      so far (not just first index, since we need to count ALL matches).
    - If (currentSum - k) has appeared 'c' times before, that means there
      are 'c' different subarrays ending here that sum to k.

    STEPS:
    ----------
    1. um[0] = 1 (empty prefix has sum 0), sum = 0, count = 0.
    2. For each element, add it to sum.
    3. If (sum - k) exists in um, add um[sum - k] to count.
    4. Increment um[sum] (record this prefix sum occurrence).
    5. Return count.

    VARIATIONS TO REMEMBER:
    ----------
    - Longest subarray with sum k (not count) -> only store FIRST index of
      each prefix sum, see longest_subarray_with_sum_k_with_negatives.cpp.
    - Subarrays with XOR equal to k -> same hashmap pattern but with XOR
      instead of sum, see subarrays_with_xor_k.cpp.

    TIME COMPLEXITY  : O(n) -> single pass with hashmap lookups
    SPACE COMPLEXITY : O(n) -> hashmap can store up to n distinct prefix sums
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> um;
        int sum = 0;
        int count = 0;

        um[0] = 1;  // sum = 0

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (um.find(sum - k) != um.end())
                count += um[sum - k];

            um[sum]++;
        }

        return count;
    }
};

int main() {
    return 0;
}