/*
    ============================================================
    TOPIC   : Sliding Window & Two Pointers - Medium
    PROBLEM : Fruit Into Baskets (max fruits with at most 2 types)
    ============================================================

    INTUITION:
    ----------
    - Same as "longest substring with at most K distinct" pattern,
      here K = 2 (only 2 basket types allowed).
    - Keep a window [i, j] that contains at most 2 distinct fruit types.
    - Expand right (j), and shrink left (i) whenever the window has
      more than 2 distinct types.

    STEPS:
    ----------
    1. Use a hashmap to count frequency of each fruit type in window.
    2. Expand j, increment count of fruits[j].
    3. While map has more than 2 distinct keys, shrink from left:
       decrement count of fruits[i], erase key if count hits 0, i++.
    4. Track max window length (j - i + 1) at every step.

    VARIATIONS TO REMEMBER:
    ----------
    - Generic "at most K distinct characters/types" -> replace hardcoded
      2 with K.
    - "Exactly K distinct" -> atMost(K) - atMost(K-1) trick.

    TIME COMPLEXITY  : O(n) -> each index enters/leaves window once
    SPACE COMPLEXITY : O(1) -> at most 3 keys in map at any time
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int i = 0, res = 0;

        for (int j = 0; j < fruits.size(); j++) {
            count[fruits[j]]++;

            // shrink window if more than 2 fruit types
            while (count.size() > 2) {
                count[fruits[i]]--;
                if (count[fruits[i]] == 0) {
                    count.erase(fruits[i]);
                }
                i++;
            }

            // window length = j - i + 1
            res = max(res, j - i + 1);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> fruits = {1, 2, 1};
    cout << s.totalFruit(fruits) << endl;  // Output: 3
    return 0;
}