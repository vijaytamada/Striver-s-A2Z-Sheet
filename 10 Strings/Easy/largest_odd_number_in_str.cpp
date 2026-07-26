/*
    ============================================================
    TOPIC   : Strings - Easy
    PROBLEM : Largest Odd Number in String
    ============================================================

    INTUITION:
    ----------
    - A number is odd only based on its last digit, and removing digits from
      the end of a number never changes the relative order of remaining
      digits.
    - So the largest odd-valued prefix is found by scanning from the right
      and cutting the string right after the first odd digit encountered.

    STEPS:
    ----------
    1. Scan the string from the last character to the first.
    2. The moment a digit is odd, return the substring from index 0 up to
       and including that digit.
    3. If no odd digit is ever found, return empty string (no valid answer).

    VARIATIONS TO REMEMBER:
    ----------
    - Similar prefix-trimming idea appears in "largest number after removing
      k digits" style problems, though those use a different (stack-based)
      technique.

    TIME COMPLEXITY  : O(n) -> scan at most once from the end
    SPACE COMPLEXITY : O(n) -> substring copy for the result
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        for (int i = num.length() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}