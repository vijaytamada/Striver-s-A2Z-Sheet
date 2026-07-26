/*
    ============================================================
    TOPIC   : Strings - Medium
    PROBLEM : String to Integer (atoi)
    ============================================================

    INTUITION:
    ----------
    - Parse the string like a state machine: skip whitespace, then an
      optional sign, then digits - stop at the first non-digit.
    - Overflow must be checked WHILE building the number (using a wider type
      like long), not after, since the final value could already overflow
      an int.

    STEPS:
    ----------
    1. Skip leading whitespace characters.
    2. Check for and consume an optional '+' or '-' sign.
    3. While current char is a digit: res = res*10 + digit.
    4. After each digit, clamp immediately if res exceeds INT_MAX (positive)
       or -res goes below INT_MIN (negative) - return the clamped bound.
    5. Stop at the first non-digit character (ignore the rest of the string).
    6. Return sign * res.

    VARIATIONS TO REMEMBER:
    ----------
    - Similar careful-overflow-handling pattern shows up in "Reverse
      Integer" and "String to Integer" variants across languages.

    TIME COMPLEXITY  : O(n) -> single pass over the string
    SPACE COMPLEXITY : O(1) -> only a few variables used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. Check and store sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Parse digits and build the number
        long res = 0;
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            // 4. Clamp overflow before it happens
            if (sign == 1 && res > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -res < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * res;
    }
};

int main() {
    return 0;
}