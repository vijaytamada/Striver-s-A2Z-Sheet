/*
    ============================================================
    TOPIC   : Greedy Algos - Easy
    PROBLEM : Valid Parenthesis String (with '*' as wildcard)
    ============================================================

    INTUITION:
    ----------
    - '*' can act as '(', ')', or empty string, so we can't just
      count brackets directly — instead do two greedy passes.
    - Left-to-right pass: treat '*' as '(' when needed to keep a
      running balance of unmatched '(' (leftCount) and available
      wildcards (wildcardCount); this checks there's never a point
      where a ')' can't be matched even using a wildcard as '('.
    - Right-to-left pass: mirror check treating '*' as ')' to ensure
      no unmatched '(' remains that even wildcards-as-')' can't close.

    STEPS:
    ----------
    1. Left-to-right: track leftCount ('(' seen) and wildcardCount
       ('*' seen). On ')': consume from leftCount first, else
       wildcardCount, else return false (unmatched close).
    2. If after this pass, no '(' or '*' remain unresolved, string
       could already be valid — but do a second pass for full safety.
    3. Right-to-left: same idea but swapped roles (rightCount for ')',
       wildcard as '(' now), catches unmatched '(' from the left.

    VARIATIONS TO REMEMBER:
    ----------
    - Alternative approach: track [minOpen, maxOpen] range of possible
      open-bracket counts as you scan left to right; '*' widens the
      range, ')' shrinks/shifts it, '(' shifts it up. Fails if maxOpen
      < 0 at any point; valid if minOpen can reach 0 by the end.

    TIME COMPLEXITY  : O(n) -> two linear passes over the string
    SPACE COMPLEXITY : O(1) -> only a few counters used
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(const std::string& s) {
        int leftCount = 0;
        int wildcardCount = 0;

        for (char c : s) {
            if (c == '(') {
                leftCount++;
            } else if (c == ')') {
                if (leftCount > 0)
                    leftCount--;
                else if (wildcardCount > 0)
                    wildcardCount--;
                else
                    return false;
            } else {
                wildcardCount++;
            }
        }

        int remainingLeft = leftCount + wildcardCount;
        if (remainingLeft == 0)
            return true;

        int rightCount = 0;
        wildcardCount = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == ')')
                rightCount++;
            else if (c == '(') {
                if (rightCount > 0)
                    rightCount--;
                else if (wildcardCount > 0)
                    wildcardCount--;
                else
                    return false;
            } else
                wildcardCount++;
        }

        return true;
    }
};

int main() {
    return 0;
}