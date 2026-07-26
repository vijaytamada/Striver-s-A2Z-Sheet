/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Longest Subarray with Sum K (array can have negatives)
    ============================================================

    INTUITION:
    ----------
    - Brute force: check every subarray with two nested loops, O(n^2).
    - Optimal: since negatives can be present, sliding window won't work
      (sum isn't guaranteed to grow/shrink monotonically). Use prefix
      sums + hashmap instead.
    - Keep running prefix sum. If (prefixSum - k) was seen before at some
      index, the subarray between that index+1 and current index sums to k.
    - Store only the FIRST occurrence of each prefix sum in the map, so we
      always get the longest possible subarray.

    STEPS:
    ----------
    1. sum = 0, hash[0] = -1 (base case: sum 0 before array starts).
    2. For each index i, add nums[i] to sum.
    3. If (sum - k) exists in hash, update res = max(res, i - hash[sum-k]).
    4. If sum itself isn't in hash yet, store hash[sum] = i.
    5. Return res.

    VARIATIONS TO REMEMBER:
    ----------
    - All positive numbers -> sliding window works and is O(1) space,
      see longest_subarray_with_sum_k.cpp.
    - Count of subarrays with sum k -> subarrays_sum_equals_k.cpp.
    - Subarray with XOR k instead of sum -> subarrays_with_xor_k.cpp.

    TIME COMPLEXITY  : O(n) -> single pass with hashmap lookups
    SPACE COMPLEXITY : O(n) -> hashmap can store up to n prefix sums
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};

class Solution2 {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> hash;  // prefix_sum -> first index
        hash[0] = -1;

        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];

            if (hash.find(sum - k) != hash.end()) {
                res = max(res, i - hash[sum - k]);
            }

            if (hash.find(sum) == hash.end()) {  // keep first occurrence only
                hash[sum] = i;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;
    cout << Solution1().longestSubarrayWithSumK(nums, k) << "\n";  // 4
    cout << Solution2().longestSubarrayWithSumK(nums, k) << "\n";  // 4
}
