/*
    ============================================================
    TOPIC   : Sliding Window & Two Pointers - Medium
    PROBLEM : Longest Repeating Character Replacement (LC 424)
    ============================================================

    INTUITION:
    ----------
    - We want the longest window where, after changing at most k
      characters, all characters become the same.
    - A window is valid if (window length - count of most frequent
      char in window) <= k, i.e. the number of characters we'd need
      to replace is within budget.
    - Grow the window greedily; only shrink when it becomes invalid.

    STEPS (Solution 2 - optimal):
    ----------
    1. Maintain freq count of chars in window[i..j] and maxCount =
       highest frequency seen in the current/any window so far.
    2. Expand j, update hash[s[j]] and maxCount.
    3. If (j - i + 1) - maxCount > k, shrink: decrement hash[s[i]], i++.
       (maxCount may be stale here, but that's fine — window size
       never actually shrinks below the best found so far.)
    4. Track res = max(res, j - i + 1) every iteration.

    NOTE:
    ----------
    - Solution1 is the brute-force-ish version: tries each of the 26
      letters as the "target" letter and slides a window counting how
      many other chars would need replacing. O(26n).

    VARIATIONS TO REMEMBER:
    ----------
    - "Max Consecutive Ones III" -> special case where alphabet = {0,1}
      and target char is always 1.
    - Longest substring without repeating chars -> different condition
      (all unique) instead of (max freq char count).

    TIME COMPLEXITY  : O(n) for Solution2 (O(26n) for Solution1)
    SPACE COMPLEXITY : O(26) -> fixed-size frequency array/map
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

// Leetcode 424: Longest Repeating Character Replacement
// Solution 1
class Solution1 {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hashMap;

        int res = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) {

            int i = 0, j = 0;
            int excluding = 0;
            while (j < s.length()) {
                if(s[j] != ch){
                    excluding++;
                }

                while(excluding > k){
                    if(s[i] != ch){
                        excluding--;
                    }
                    i++;
                }
                res = max(res, j - i + 1);
                j++;
            }
        }

        return res;
    }
};

// Solution 2
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0);

        int i = 0, j = 0;
        int maxCount = 0;
        int res = 0;

        while(j < s.length()){
            hash[s[j] - 'A']++;
            maxCount = max(maxCount, hash[s[j] - 'A']);

            while((j-i+1) - maxCount > k){
                hash[s[i] - 'A']--;
                i++;
            }

            res = max(res, j - i + 1);
            j++;
        }

        return res;
    }
};

int main()
{
    

    return 0;
}