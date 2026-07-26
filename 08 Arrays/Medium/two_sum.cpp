/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Two Sum
    ============================================================

    INTUITION:
    ----------
    - Brute force: check every pair with two nested loops, O(n^2).
    - Optimal (hashmap): for each element, compute the "complement"
      (target - current). If we've already seen that complement before,
      we found our pair immediately - no need to search again.
    - A two-pointer version also works but requires the array to be
      SORTED first (and note: sorting loses original indices unless
      tracked separately, so it changes what the returned indices mean).

    STEPS (Hashmap - optimal):
    ----------
    1. Create an empty hash map (value -> index).
    2. For each index i: compute complement = target - nums[i].
    3. If complement exists in hash, return {hash[complement], i}.
    4. Otherwise, store hash[nums[i]] = i and continue.

    VARIATIONS TO REMEMBER:
    ----------
    - "3 Sum" / "4 Sum" -> fix one/two elements and reduce to two-pointer
      two sum on the rest (see 3_sum.cpp, 4_sum.cpp).
    - If array is already sorted, two-pointer approach avoids extra space.

    TIME COMPLEXITY  : O(n) -> single pass with hashmap (brute force is O(n^2))
    SPACE COMPLEXITY : O(n) -> hashmap stores up to n elements
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Brute force - Using for loops
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

// Using hashmap
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }

            hash[nums[i]] = i;
        }

        return {};
    }
};

// Using two pointers (only for sorted array)
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // Ensure the array is sorted
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                return {left, right};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};

int main() {
    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result1 = sol1.twoSum(nums, target);
    vector<int> result2 = sol2.twoSum(nums, target);
    vector<int> result3 = sol3.twoSum(nums, target);
    return 0;
}