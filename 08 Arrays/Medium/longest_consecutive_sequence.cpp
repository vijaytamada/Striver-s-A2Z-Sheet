/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Longest Consecutive Sequence
    ============================================================

    INTUITION:
    ----------
    - Brute force: sort the array first, then walk through counting
      consecutive runs. Works but pays O(n log n) for sorting.
    - Optimal: dump everything into a hash set for O(1) lookups. For each
      number, only start counting a sequence if it's the START of one
      (i.e., number-1 does NOT exist in the set). This way every sequence
      gets counted exactly once instead of re-walking from every element.

    STEPS (Optimal):
    ----------
    1. Insert all elements into an unordered_set.
    2. For each element in the set, check if (element - 1) exists.
       If it does, skip it (it's not the start of a sequence).
    3. If it's a valid start, keep incrementing and checking element+1,
       element+2... counting the run length.
    4. Track the max run length found.

    VARIATIONS TO REMEMBER:
    ----------
    - "Longest consecutive sequence in a binary tree" - same core idea but
      applied to tree paths.
    - Union-Find can also solve this by union-ing consecutive numbers.

    TIME COMPLEXITY  : O(n) optimal (each number visited O(1) amortized total across all sequences) - brute force is O(n log n)
    SPACE COMPLEXITY : O(n) -> hash set stores all elements
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach - O(N log N) time, O(1) space
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int len = 0;
        int res = 1;
        int curr = nums[0] - 1;

        for (auto& it : nums) {
            if (curr == it) {
                continue;
            }

            if (curr + 1 == it) {
                len++;
                curr++;
                res = max(res, len);
            } else {
                curr = it;
                len = 1;
            }
        }

        return res;
    }
};

// Optimal Approach - O(N) time, O(N) space
class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        unordered_set<int> hashSet;
        for (auto& it : nums) {
            hashSet.insert(it);
        }

        int res = 0;
        for (auto& it : hashSet) {
            int ele = it;
            int len = 0;
            if (hashSet.find(ele - 1) == hashSet.end()) {
                while (hashSet.find(ele) != hashSet.end()) {
                    len++;
                    ele++;
                }
                res = max(res, len);
            }
        }

        return res;
    }
};

int main() {
    return 0;
}