/*
    ============================================================
    TOPIC   : Strings - Easy
    PROBLEM : Isomorphic Strings
    ============================================================

    INTUITION:
    ----------
    - Two strings are isomorphic if there's a consistent one-to-one character
      mapping from s to t (and back) at every position.
    - Track, for each character, the last index it appeared at in both
      strings - if s[i] and t[i] don't have matching "last seen" positions,
      the mapping is broken. Equivalently, maintain a direct char->char map
      in both directions and ensure it's never contradicted.

    STEPS:
    ----------
    1. (Solution1) Two maps store last-seen-index+1 for each char in s and t.
    2. For each position i, compare m1[s[i]] vs m2[t[i]] - if different, the
       mapping is inconsistent, return false.
    3. Update both maps with i+1 and continue; return true if loop completes.
    4. (Solution2) Alternative - maintain direct s->t and t->s character maps
       and verify they never conflict.

    VARIATIONS TO REMEMBER:
    ----------
    - Word Pattern (LeetCode) is the same idea applied to words instead of
      characters.

    TIME COMPLEXITY  : O(n) -> single pass over the strings
    SPACE COMPLEXITY : O(1) -> at most 256 characters in the maps
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Solution1 - Using two hash maps to store count
class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> m1, m2;

        for (int i = 0; i < s.length(); i++) {
            if (m1[s[i]] != m2[t[i]])
                return false;

            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }

        return true;
    }
};

// Solution2 - Using two hash maps to store character mapping
class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> charMap, revMap;

        for (int i = 0; i < s.length(); i++) {
            if (charMap.find(s[i]) == charMap.end() && revMap.find(t[i]) == charMap.end()) {
                charMap[s[i]] = t[i];
                revMap[t[i]] = s[i];
            } else {
                if (charMap[s[i]] != t[i] || revMap[t[i]] != s[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    return 0;
}