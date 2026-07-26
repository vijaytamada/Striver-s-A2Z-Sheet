/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : 4Sum (find all unique quadruplets that sum to target)
    ============================================================

    INTUITION:
    ----------
    - Brute force: four nested loops checking every quadruplet, O(n^4),
      dedupe using a set.
    - Optimal: sort the array, then fix TWO elements with nested loops (i, j),
      and use two-pointer technique on the remaining subarray to find pairs
      summing to (target - nums[i] - nums[j]).
    - Use `long long` for sums to avoid integer overflow, and skip duplicate
      values at every level (i, j, left, right) to avoid duplicate quadruplets.

    STEPS (Optimal):
    ----------
    1. Sort nums.
    2. For i from 0 to n-4 (skip duplicates of i).
    3. For j from i+1 to n-3 (skip duplicates of j).
    4. left = j+1, right = n-1; two-pointer scan same as 3Sum:
       if sum == target, record and skip duplicate left/right, move inward;
       if sum < target, left++; else right--.

    VARIATIONS TO REMEMBER:
    ----------
    - 3Sum -> the simpler version this builds on, fixing only one element
      (see 3_sum.cpp).
    - "K Sum" generalizes this pattern recursively: fix elements one at a
      time until only 2 remain, then two-pointer.

    TIME COMPLEXITY  : O(n^3) -> sort + two nested loops * O(n) two-pointer scan (brute force is O(n^4))
    SPACE COMPLEXITY : O(1) extra (excluding output)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    for (int l = k + 1; l < n; ++l) {
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == target) {
                            res.insert({nums[i], nums[j], nums[k], nums[l]});
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};

// Optimal Approach using Two Pointers
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                            ++left;
                        while (left < right && nums[right] == nums[right - 1])
                            --right;

                        ++left;
                        --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    return 0;
}