/*
    ============================================================
    TOPIC   : Strings - Easy
    PROBLEM : Remove Outermost Parentheses
    ============================================================

    INTUITION:
    ----------
    - The string is a sequence of "primitive" balanced groups; each group's
      outermost opening and closing bracket should be dropped, only the
      inner brackets kept.
    - Track a running open-bracket count: the very first '(' of a group
      (count going 0->1) and the very last ')' of a group (count going 1->0)
      are the outer ones to skip; everything else at depth >= 2 is kept.

    STEPS:
    ----------
    1. openCount = 0, res = "".
    2. For each character: if '(' -> increment openCount first, then only
       append it if openCount >= 2 (i.e. it's not the group's opening bracket).
    3. If ')' -> only append it if openCount >= 2 (not the group's closing
       bracket), then decrement openCount.
    4. Return res.

    VARIATIONS TO REMEMBER:
    ----------
    - Related to "Maximum Nesting Depth of Parentheses" which tracks the same
      openCount but takes its max instead of filtering characters.

    TIME COMPLEXITY  : O(n) -> single pass over the string
    SPACE COMPLEXITY : O(n) -> result string storage
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int openCount = 0;
        string res = "";

        for (char &ch : s) {
            if (ch == '(') {
                openCount++;
                if (openCount >= 2) {
                    res.push_back('(');
                }
            } else {
                if (openCount >= 2) {
                    res.push_back(')');
                }
                openCount--;
            }
        }

        return res;
    }
};

int main() {
    return 0;
}