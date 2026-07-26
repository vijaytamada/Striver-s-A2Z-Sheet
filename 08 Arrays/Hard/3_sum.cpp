/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : 3Sum (find all unique triplets that sum to 0)
    ============================================================

    INTUITION:
    ----------
    - Brute force: three nested loops checking every triplet, O(n^3), using
      a set to dedupe results.
    - Optimal: sort the array first. Fix one element (i), then use the
      two-pointer technique on the rest of the array to find pairs that
      sum to -nums[i] - this reduces the inner two loops to one linear scan.
    - Skip duplicate values for i, left, and right pointers to avoid
      duplicate triplets in the result (no need for a set).

    STEPS (Optimal):
    ----------
    1. Sort nums.
    2. For each i from 0 to n-1 (skip if same as previous i to avoid dupes):
       - left = i+1, right = n-1.
       - While left < right: compute sum = nums[i]+nums[left]+nums[right].
       - If sum == 0, record triplet, then skip duplicate left/right values,
         and move both pointers inward.
       - If sum < 0, left++; if sum > 0, right--.

    VARIATIONS TO REMEMBER:
    ----------
    - Two Sum -> the base case this builds on (see two_sum.cpp).
    - 4Sum -> fix two elements instead of one, then two-pointer the rest
      (see 4_sum.cpp).
    - "3Sum Closest" -> same two-pointer setup but track closest sum to
      target instead of exact matches.

    TIME COMPLEXITY  : O(n^2) -> sort O(n log n) + O(n) outer loop * O(n) two-pointer scan (brute force is O(n^3))
    SPACE COMPLEXITY : O(1) extra (excluding output; sort may use O(log n) stack space)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        res.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};

// Optimal Approach using Two Pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right && nums[right] == nums[right - 1])
                        --right;
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return res;
    }
};

int main() {
    return 0;
}