/*
    ============================================================
    TOPIC   : Strings - Medium
    PROBLEM : Roman to Integer
    ============================================================

    INTUITION:
    ----------
    - Normally you add each symbol's value, but when a smaller-value symbol
      appears immediately before a larger one (like IV, IX), it represents
      subtraction instead of addition.
    - Compare each symbol's value to the NEXT symbol's value: if smaller,
      subtract it; otherwise add it. The very last symbol is always added.

    STEPS:
    ----------
    1. Build a char->value map for I, V, X, L, C, D, M.
    2. For i from 0 to n-2: if value(s[i]) < value(s[i+1]) -> subtract
       value(s[i]) from result (subtractive pair like IV, IX, XL, etc.);
       else -> add value(s[i]).
    3. Always add value(s[n-1]) (the last symbol) at the end.
    4. Return result.

    VARIATIONS TO REMEMBER:
    ----------
    - Integer to Roman is the reverse problem, solved with greedy symbol
      subtraction instead of pairwise comparison.

    TIME COMPLEXITY  : O(n) -> single pass over the string
    SPACE COMPLEXITY : O(1) -> fixed-size symbol value map
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(const string& s) {
        unordered_map<char, int> valueMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int res = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (valueMap[s[i]] < valueMap[s[i + 1]])
                res -= valueMap[s[i]];
            else
                res += valueMap[s[i]];
        }

        res += valueMap[s.back()];
        return res;
    }
};

int main() {
    return 0;
}