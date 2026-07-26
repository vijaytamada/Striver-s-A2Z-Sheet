/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS
    PROBLEM : Word Ladder I (shortest transformation length)
    ============================================================

    INTUITION:
    ----------
    - Model each word as a node; an edge connects two words that differ
      by exactly one letter. "Minimum transformations from beginWord to
      endWord" then becomes shortest path in an unweighted graph -> BFS.
    - Solution1 explicitly builds the adjacency list by comparing every
      pair of words (slow, easy to follow). Solution2 skips building
      the graph -- for each word popped from the queue, it tries
      changing every letter position to every other letter ('a'-'z')
      and checks if the result is in the dictionary (faster in practice).

    STEPS (Solution2, the efficient one):
    ----------
    1. If endWord isn't in the word list, return 0 (impossible).
    2. BFS starting from beginWord with steps = 1.
    3. For each popped word, try all 26 letters at every position; if
       the resulting word is in the dictionary and unvisited, mark it
       visited and push it with steps + 1.
    4. If the popped word equals endWord, return its steps.
    5. If the queue empties without finding endWord, return 0.

    VARIATIONS TO REMEMBER:
    ----------
    - Word Ladder II asks for ALL shortest transformation sequences,
      not just the length -- needs BFS for shortest distance plus a
      backtracking/DFS step to reconstruct every path
      (see word_ladder_II.cpp note).

    TIME COMPLEXITY  : O(N * L * 26) -> N words, L = word length (Solution2)
    SPACE COMPLEXITY : O(N * L) -> dictionary set + visited set + queue
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1 : BFS using Adjacency List created from word list
class Solution1 {
public:
    bool validTransformation(const string& word1, const string& word2) {
        int diff = 0;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i])
                diff++;
            if (diff > 1)
                return false;
        }
        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string, vector<string>> adj;

        // Build adjacency list for dictionary words
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (validTransformation(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        // If endWord not in dictionary, no solution
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return 0;

        // Connect beginWord to dictionary words
        bool flag = false;
        for (auto& w : wordList) {
            if (validTransformation(beginWord, w)) {
                adj[beginWord].push_back(w);
                adj[w].push_back(beginWord);
                flag = true;
            }
        }

        if (flag == false)
            return 0;

        // BFS from beginWord
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> vis;
        vis.insert(beginWord);

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord)
                return steps;

            for (auto& nei : adj[word]) {
                if (!vis.count(nei)) {
                    vis.insert(nei);
                    q.push({nei, steps + 1});
                }
            }
        }

        return 0;  // unreachable
    }
};

// Solution 2 : Optimized BFS without explicit graph construction
class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // BFS from beginWord
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return 0;  // endWord must be in wordList

        queue<pair<string, int>> q;
        q.push({beginWord, 1});  // start with length 1
        unordered_set<string> vis;
        vis.insert(beginWord);

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord)
                return steps;

            // Try all possible one-letter transformations
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dict.count(temp) && !vis.count(temp)) {
                        vis.insert(temp);
                        q.push({temp, steps + 1});
                    }
                }
            }
        }

        return 0;  // no transformation found
    }
};

int main() {
    return 0;
}