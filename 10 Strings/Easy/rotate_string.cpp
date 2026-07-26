/*
    ============================================================
    TOPIC   : Strings - Easy
    PROBLEM : Rotate String (check if goal is a rotation of s)
    ============================================================

    INTUITION:
    ----------
    - Any rotation of s is a substring of (s + s) - concatenating s with
      itself lays out every possible rotation back to back.
    - So goal is a rotation of s if and only if goal is a substring of s+s
      (with matching lengths).

    STEPS:
    ----------
    1. (Solution1, Brute Force) Repeatedly rotate s by moving its first char
       to the end (s.substr(1) + s[0]) and compare with goal each time, up to
       n rotations.
    2. (Solution2, Optimized) If lengths differ, return false. Else check
       whether goal is found inside (s + s) using string::find.

    VARIATIONS TO REMEMBER:
    ----------
    - Same "double the string" trick is used in circular array problems
      (e.g. max subarray sum in circular array, checking circular subarrays).

    TIME COMPLEXITY  : O(n^2) brute force -> n rotations each costing O(n) to build/compare;
                        O(n) optimized -> substring search in a string of length 2n
    SPACE COMPLEXITY : O(n) -> extra string(s) built during rotation/concatenation
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Solution - Brute Force
class Solution1 {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        for (int i = 0; i < s.length(); i++) {
            string rotated = s.substr(1) + s[0];
            s = rotated;

            if (rotated == goal)
                return true;
        }

        return false;
    }
};

// Optimized Solution - Using string concatenation
class Solution2 {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        return (s + s).find(goal) != string::npos;
    }
};

int main() {
    return 0;
}