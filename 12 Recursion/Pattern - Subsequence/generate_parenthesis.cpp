/*
    ============================================================
    TOPIC   : Recursion - Pattern - Subsequence
    PROBLEM : Generate Parentheses (all valid combinations of n pairs)
    ============================================================

    INTUITION:
    ----------
    - A parenthesis string is valid only if at every prefix the number
      of closing brackets never exceeds the number of opening brackets,
      and both counts end at 0.
    - Track remaining '(' and ')' to place; only allow placing ')' when
      more of them remain than '(' remain (i.e. an unmatched '(' exists).

    STEPS:
    ----------
    1. Base case: if both open and close counts reach 0, the string is
       complete and valid — save it to the result.
    2. If open count > 0, recurse adding '(' and decrementing open.
    3. If close count > 0 AND close > open (meaning there's an unmatched
       '(' to close), recurse adding ')' and decrementing close.
    4. Collect all completed valid strings in `res`.

    VARIATIONS TO REMEMBER:
    ----------
    - Generate all binary strings with no consecutive 1s
      (generate_all_binary_strings.cpp) uses the same pick/don't-pick
      recursion shape with a different validity rule.
    - Checking if a given parenthesis string is balanced uses a stack
      instead of generating combinations (see balanced_parenthesis.cpp).

    TIME COMPLEXITY  : O(4^n / sqrt(n)) -> bounded by the nth Catalan number of valid combinations
    SPACE COMPLEXITY : O(n) -> recursion depth is 2n (excluding output storage)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int open, int close, string currStr, vector<string>& res) {
        if (open == 0 && close == 0) {
            res.push_back(currStr);
            return;
        }

        if (open > 0) {
            helper(open - 1, close, currStr + '(', res);
        }

        if (close > 0 && close > open) {
            helper(open, close - 1, currStr + ')', res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, n, "", res);
        return res;
    }
};

int main() {
    return 0;
}