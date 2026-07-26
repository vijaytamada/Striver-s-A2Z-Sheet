/*
    ============================================================
    TOPIC   : Strings - Medium
    PROBLEM : Sort Characters By Frequency
    ============================================================

    INTUITION:
    ----------
    - The output only cares about how often each character appears, not its
      original position, so first count frequencies, then reorder characters
      by that count.
    - A custom comparator sorting by descending frequency (with a tie-break)
      does this directly on the character array.

    STEPS:
    ----------
    1. Count the frequency of every character in s using a hash map.
    2. Sort the characters of s using a custom comparator: higher frequency
       comes first; if frequencies are equal, break ties by char value.
    3. Return the sorted string.

    VARIATIONS TO REMEMBER:
    ----------
    - Could also use a max-heap or bucket sort by frequency for O(n) instead
      of O(n log n) if frequency range is bounded.
    - Top K Frequent Elements is the analogous problem for array elements.

    TIME COMPLEXITY  : O(n log n) -> sorting the characters dominates
    SPACE COMPLEXITY : O(1) -> frequency map bounded by character set size
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequencies of all characters
        for (char ch : s) {
            freq[ch]++;
        }

        // Sort based on frequency (and char if needed)
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (freq[a] == freq[b])
                return a < b;  // optional tie-breaker
            return freq[a] > freq[b];
        });

        return s;
    }
};

int main() {
    return 0;
}