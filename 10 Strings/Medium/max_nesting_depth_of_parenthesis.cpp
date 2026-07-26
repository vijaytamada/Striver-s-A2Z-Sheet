/*
    ============================================================
    TOPIC   : Strings - Medium
    PROBLEM : Maximum Nesting Depth of the Parentheses
    ============================================================

    INTUITION:
    ----------
    - The "depth" at any point is just how many '(' have been opened but not
      yet closed - a running counter.
    - Track that counter as it rises on '(' and falls on ')', and keep the
      maximum value it ever reaches.

    STEPS:
    ----------
    1. open = 0, res = 0.
    2. For each character: if '(' -> open++, then res = max(res, open).
    3. If ')' -> open--.
    4. Return res.

    VARIATIONS TO REMEMBER:
    ----------
    - Same "openCount" tracking as "Remove Outermost Parentheses", but here
      we take the max instead of filtering characters at depth 1.

    TIME COMPLEXITY  : O(n) -> single pass over the string
    SPACE COMPLEXITY : O(1) -> only a couple of counters used
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int res = 0;

        for (char &ch : s) {
            if (ch == '(') {
                open++;
                res = max(res, open);
            } else if (ch == ')') {
                open--;
            }
        }

        return res;
    }
};

int main() {
    return 0;
}