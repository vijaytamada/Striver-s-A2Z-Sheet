/*
    ============================================================
    TOPIC   : Recursion - Pattern - Subsequence
    PROBLEM : Generate All Binary Strings of Length n with No Two
              Consecutive 1s
    ============================================================

    INTUITION:
    ----------
    - This is a "pick / don't pick" style recursion over each position:
      at every position you can always place '0', but can only place
      '1' if the previous character wasn't already '1'.
    - Recursion builds the string one character at a time and only
      records it once it reaches the target length n.

    STEPS:
    ----------
    1. Base case: if currStr's length equals n, save it to the result
       and return.
    2. Always recurse by appending '0' (never breaks the constraint).
    3. Recurse by appending '1' only if currStr is empty or its last
       character isn't '1'.
    4. Collect all completed strings in `res`.

    VARIATIONS TO REMEMBER:
    ----------
    - Generate all subsequences / subsets uses the same pick/don't-pick
      recursion shape without the adjacency constraint.
    - Generate parentheses (generate_parenthesis.cpp) is the same
      pattern with a different validity rule (open/close counts).

    TIME COMPLEXITY  : O(2^n) -> worst case branches into two choices per position
    SPACE COMPLEXITY : O(n) -> recursion depth equals string length (excluding output storage)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int n, string currStr, vector<string>& res) {
        if ((int)currStr.length() == n) {
            res.push_back(currStr);
            return;
        }

        // Always safe to add '0'
        helper(n, currStr + '0', res);

        // Add '1' only if last char is not '1'
        if (currStr.empty() || currStr.back() != '1') {
            helper(n, currStr + '1', res);
        }
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> res;
        helper(n, "", res);
        return res;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<string> ans = sol.generateBinaryStrings(n);

    for (auto &s : ans) {
        cout << s << "\n";
    }
    return 0;
}