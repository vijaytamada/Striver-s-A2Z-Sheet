/*
    ============================================================
    TOPIC   : Sliding Window & Two Pointers - Medium
    PROBLEM : Longest Substring Without Repeating Characters
    ============================================================

    INTUITION:
    ----------
    - Use a window [left, right] that always contains unique characters.
    - Expand right one step at a time. If the new character is already
      inside the window, shrink from the left until the duplicate is gone
      — no need to restart the whole window from scratch.
    - Track the max window size seen throughout.

    STEPS:
    ----------
    1. Use a hashmap/set to store the last seen index of each character.
    2. Move `right` pointer through the string.
    3. If arr[right] was seen before AND its last index >= left, jump
       left to (lastIndex + 1).
    4. Update max length = right - left + 1 at every step.

    VARIATIONS TO REMEMBER:
    ----------
    - "At most K distinct characters" -> same window idea, shrink when
      distinct count > K instead of on duplicate.
    - "Longest repeating character replacement" -> shrink when
      (window size - count of most frequent char) > K.

    TIME COMPLEXITY  : O(n) -> each pointer moves forward at most n times
    SPACE COMPLEXITY : O(min(n, charset size)) -> hashmap of characters
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;

        int i = 0;
        int j = 0;
        int res = 0;

        while (i <= j && j < s.length()) {
            if (hash[s[j]] == 0) {
                hash[s[j]] = 1;
                res = max(res, j - i + 1);
                j++;
            } else {
                hash[s[i]] = 0;
                i++;
            }
        }

        return res;
    }
};

int main() {
    return 0;
}