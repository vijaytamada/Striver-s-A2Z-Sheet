/*
    ============================================================
    TOPIC   : Strings - Easy
    PROBLEM : Longest Common Prefix
    ============================================================

    INTUITION:
    ----------
    - The common prefix can only be as long as the shortest string, and every
      character position must match across ALL strings simultaneously.
    - Walk character by character (column by column across all strings);
      stop at the first mismatch or when any string runs out.

    STEPS:
    ----------
    1. If strs is empty, return "".
    2. For each index idx starting at 0: take strs[0][idx] as the char to
       match.
    3. Compare that char against strs[i][idx] for every other string; if any
       string is too short or has a different char, stop.
    4. If all strings matched at idx, append the char to result and move to
       idx+1; else break out.
    5. Return the accumulated result.

    VARIATIONS TO REMEMBER:
    ----------
    - Could also sort the array and just compare the first and last strings
      (common prefix of the whole set = common prefix of the two extremes).
    - Trie-based approach generalizes to prefix queries on many strings.

    TIME COMPLEXITY  : O(n*m) -> n strings, m = length of shortest string
    SPACE COMPLEXITY : O(m) -> result string storage
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string res = "";
        bool found = true;
        int idx = 0;

        while (found) {
            // stop if idx goes beyond first string
            if (idx >= strs[0].length())
                break;

            char ch = strs[0][idx];

            for (int i = 1; i < strs.size(); i++) {
                // stop if string is too short or mismatch found
                if (idx >= strs[i].length() || strs[i][idx] != ch) {
                    found = false;
                    break;
                }
            }

            if (!found)
                break;

            res.push_back(ch);
            idx++;
        }

        return res;
    }
};

int main() {
    return 0;
}