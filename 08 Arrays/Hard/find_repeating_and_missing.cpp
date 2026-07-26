/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : Find the Repeating and Missing Number (array has 1..n, one
              number repeated, one missing)
    ============================================================

    INTUITION:
    ----------
    - Sorting approach: sort the array, then a repeated number shows up as
      two equal adjacent values; separately mark which numbers 1..n were
      seen to find the missing one.
    - HashMap approach: count frequency of every number 1..n; the one with
      freq 2 is repeating, the one with freq 0 is missing.
    - Math approach (most optimal, no extra space): let A = repeating,
      B = missing. Using sum formula, S1 - S = A - B (diff of sums).
      Using sum-of-squares formula, P1 - P = A^2 - B^2 = (A-B)(A+B), so
      dividing gives A+B. Solving the two linear equations (A-B and A+B)
      gives both A and B directly.

    STEPS (Math approach):
    ----------
    1. Compute expected sum S = n(n+1)/2 and expected sum of squares
       P = n(n+1)(2n+1)/6.
    2. Compute actual sum S1 and actual sum of squares P1 from the array.
    3. diff = S1 - S (this is A - B).
    4. squareDiff = P1 - P = (A-B)(A+B), so sum = squareDiff / diff (this is A + B).
    5. Solve: A = (diff + sum) / 2, B = A - diff.

    VARIATIONS TO REMEMBER:
    ----------
    - If only ONE number is missing (no repeat), see find_missing_number.cpp.
    - Three approaches are implemented below as Solution1 (sorting),
      Solution2 (hashmap), Solution3 (math) - compare all three for revision.

    TIME COMPLEXITY  : O(n) -> math approach uses a single pass (sorting approach is O(n log n))
    SPACE COMPLEXITY : O(1) -> math approach uses no extra array (hashmap/sorting approaches use O(n))
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Solution using Sorting
class Solution1 {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int missing = -1, repeating = -1;

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                repeating = nums[i];
            }
        }

        // Check for missing number
        vector<bool> seen(n + 1, false);
        for (int num : nums)
            seen[num] = true;
        for (int i = 1; i <= n; ++i) {
            if (!seen[i]) {
                missing = i;
                break;
            }
        }

        return {repeating, missing};
    }
};

// Solution using HashMap
class Solution2 {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int missing = -1, repeating = -1;

        for (int num : nums)
            freq[num]++;

        for (int i = 1; i <= n; ++i) {
            if (freq[i] == 2)
                repeating = i;
            else if (freq[i] == 0)
                missing = i;
        }

        return {repeating, missing};
    }
};

// Solution using Math
class Solution3 {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        long long n = nums.size();
        long long S = n * (n + 1) / 2;
        long long P = n * (n + 1) * (2 * n + 1) / 6;

        long long S1 = 0, P1 = 0;
        for (int num : nums) {
            S1 += num;
            P1 += (long long)num * num;
        }

        long long diff = S1 - S;        // A - B
        long long squareDiff = P1 - P;  // A² - B²

        long long sum = squareDiff / diff;  // A + B

        int A = (diff + sum) / 2;
        int B = A - diff;

        return {A, B};
    }
};

int main() {
    return 0;
}