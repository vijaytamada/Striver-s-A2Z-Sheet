/*
    ============================================================
    TOPIC   : Arrays - Easy
    PROBLEM : Longest Subarray with Sum K (positive numbers only)
    ============================================================

    INTUITION:
    ----------
    - Brute force: try every subarray (two nested loops), O(n^2)/O(n^3)-ish.
    - Optimal (sliding window works because all numbers are POSITIVE, so
      sum only increases as window grows and decreases as it shrinks -
      this monotonic behavior is what makes sliding window valid):
      grow the window by adding nums[right]; if sum exceeds k, shrink
      from the left until sum <= k again; whenever sum == k, update answer.
    - A hashmap approach (prefix sum -> first index) also works generally
      (even with negatives, see the _with_negatives variant) but uses O(n) space.

    STEPS:
    ----------
    1. left = 0, sum = 0, res = 0.
    2. For right from 0 to n-1: add nums[right] to sum.
    3. While sum > k, subtract nums[left] and move left forward.
    4. If sum == k, update res = max(res, right - left + 1).
    5. Return res.

    VARIATIONS TO REMEMBER:
    ----------
    - Array has negative numbers too -> sliding window breaks (sum isn't
      monotonic), must use prefix sum + hashmap instead.
    - Count of subarrays with sum k (not just longest) -> subarrays_sum_equals_k.cpp.

    TIME COMPLEXITY  : O(n) -> sliding window, each pointer moves forward at most n times
    SPACE COMPLEXITY : O(1) for sliding window; O(n) for the hashmap version
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// longest subarray with sum k (only for positive numbers)

// Soln 1 - Using for loops
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
                    break;
                }

                if (sum > k)
                    break;
            }
        }

        return res;
    }
};

// Soln 2 - Using Hashing
class Solution2 {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> hash;  // {prefix_sum, index}
        hash[0] = -1; // sum = 0 at index -1

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (hash.find(sum - k) != hash.end()) {
                res = max(res, i - hash[sum - k]);
            }

            // Only store first occurrence to maximize length
            if (hash.find(sum) == hash.end()) {
                hash[sum] = i;
            }
        }

        return res;
    }
};

// Soln 3 - Using Sliding Window
class Solution3 {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (left <= right && sum > k) {
                sum -= nums[left++];
            }

            if (sum == k) {
                res = max(res, right - left + 1);
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 1, 4, 2};
    int k = 5;
    cout << Solution1().longestSubarrayWithSumK(nums, k) << "\n";
    cout << Solution2().longestSubarrayWithSumK(nums, k) << "\n";
    cout << Solution3().longestSubarrayWithSumK(nums, k) << "\n";
    return 0;
}