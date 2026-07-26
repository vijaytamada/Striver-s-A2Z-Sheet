/*
    ============================================================
    TOPIC   : Strings - Medium
    PROBLEM : Integer to Roman
    ============================================================

    INTUITION:
    ----------
    - Roman numerals are built greedily from the largest possible symbol
      value downward, including the "subtractive" combos (CM, CD, XC, XL,
      IX, IV) treated as single units of their own value.
    - Repeatedly subtract the biggest value that fits and append its symbol,
      until num reaches 0.

    STEPS:
    ----------
    1. Define an ordered list of (symbol, value) pairs from largest (M=1000)
       to smallest (I=1), including subtractive pairs (CM=900, CD=400, etc).
    2. For each pair in order: while num >= value, subtract value from num
       and append the symbol to result.
    3. Return the accumulated result once num reaches 0.

    VARIATIONS TO REMEMBER:
    ----------
    - Roman to Integer is the reverse problem, solved differently (compare
      adjacent symbol values instead of greedy subtraction).

    TIME COMPLEXITY  : O(1) -> bounded number of symbols/iterations (num <= 3999 typically)
    SPACE COMPLEXITY : O(1) -> fixed-size symbol table, output length bounded
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<pair<string, int>> valueMap = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};

        for (const auto& [roman, value] : valueMap) {
            while (num >= value) {
                num -= value;
                res += roman;
            }
        }

        return res;
    }
};

int main() {
    return 0;
}