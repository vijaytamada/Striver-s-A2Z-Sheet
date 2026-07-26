/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS
    PROBLEM : Word Ladder II (all shortest transformation sequences)
    ============================================================

    INTUITION:
    ----------
    - First find the shortest distance using BFS, level by level (like
      Word Ladder I), but instead of stopping at the first hit, remember
      which word(s) at the PREVIOUS level led to each newly found word
      (its "parents").
    - Once endWord is discovered, walk BACKWARDS from endWord to
      beginWord using the parents map. Because parents only ever point
      one level back, every path found this way is automatically a
      shortest path.

    STEPS:
    ----------
    1. BFS level by level from beginWord. At each level, try every
       one-letter change of every word currently in that level.
    2. If a transformed word exists in the dictionary, add it to the
       NEXT level's set and record the current word as one of its
       parents (a word can have multiple parents at the same level).
    3. Only erase words from the dictionary AFTER finishing a whole
       level -- this lets multiple same-level words all point to the
       same child, and stops a word from reappearing at a later level.
    4. Stop expanding once endWord is found in some level.
    5. Backtrack (DFS) from endWord to beginWord using the parents map,
       collecting every path; reverse each completed path before adding
       it to the result.

    VARIATIONS TO REMEMBER:
    ----------
    - Word Ladder I only needs the shortest LENGTH -> plain BFS, no
      parent tracking or backtracking needed (see word_ladder_I.cpp).
    - This "BFS to find levels, then DFS/backtrack over parents" pattern
      also shows up in "print all shortest paths" style graph problems.

    TIME COMPLEXITY  : O(N * L^2 * 26) for the level-by-level BFS
                        (N = word count, L = word length); backtracking
                        cost on top of that depends on how many shortest
                        paths actually exist.
    SPACE COMPLEXITY : O(N * L) -> dictionary, parents map, level sets
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                        vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return result;

        // parents[word] = list of words that reach `word` on a shortest path
        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel{beginWord};
        dict.erase(beginWord);
        bool found = false;

        while (!currentLevel.empty() && !found) {
            // Words used at this level must not be reused at a later level
            for (auto& word : currentLevel)
                dict.erase(word);

            unordered_set<string> nextLevel;
            for (auto& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < (int)temp.size(); i++) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original)
                            continue;
                        temp[i] = c;
                        if (dict.count(temp)) {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord)
                                found = true;
                        }
                    }
                    temp[i] = original;
                }
            }
            currentLevel = nextLevel;
        }

        if (!found)
            return result;

        // DFS backtrack from endWord to beginWord using the parents map
        vector<string> path{endWord};
        function<void(const string&)> backtrack = [&](const string& word) {
            if (word == beginWord) {
                vector<string> full(path.rbegin(), path.rend());
                result.push_back(full);
                return;
            }
            for (auto& p : parents[word]) {
                path.push_back(p);
                backtrack(p);
                path.pop_back();
            }
        };
        backtrack(endWord);

        return result;
    }
};

int main() {
    return 0;
}