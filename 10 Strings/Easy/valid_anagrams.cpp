/*
    ============================================================
    TOPIC   : Strings - Easy
    PROBLEM : Valid Anagram
    ============================================================

    INTUITION:
    ----------
    - Two strings are anagrams if they contain exactly the same characters
      with the same frequencies, regardless of order.
    - Either sort both and compare (order becomes irrelevant), or count
      character frequencies in one string and "consume" them while scanning
      the other.

    STEPS:
    ----------
    1. (Solution - Sorting) Sort both s and t, then check equality directly.
    2. (Optimized - Hash Map) If lengths differ, return false immediately.
       Build a frequency map from s.
    3. For each char in t: if it's missing from the map or its count is
       already 0, return false; otherwise decrement its count.
    4. If the full scan completes, return true.

    VARIATIONS TO REMEMBER:
    ----------
    - Group Anagrams: bucket multiple strings by their sorted form or
      frequency signature.
    - Find All Anagrams in a String: sliding window version of this
      frequency-matching idea.

    TIME COMPLEXITY  : O(n log n) sorting version -> sort cost dominates;
                        O(n) hash map version -> single pass with O(1) map ops
    SPACE COMPLEXITY : O(1) hash map version -> at most 256 characters tracked
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Solution - Sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Optimized Solution - Using hash map to store count
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> counter;

        for (char ch : s) {
            counter[ch] = counter[ch] + 1;
        }

        for (char ch : t) {
            if (counter.find(ch) == counter.end() || counter[ch] == 0) {
                return false;
            }
            counter[ch] = counter[ch] - 1;
        }

        return true;
    }
};

int main() {
    return 0;
}