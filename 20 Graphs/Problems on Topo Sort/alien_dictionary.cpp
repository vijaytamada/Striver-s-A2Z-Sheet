/*
    ============================================================
    TOPIC   : Graphs - Topo Sort
    PROBLEM : Alien Dictionary
    ============================================================

    INTUITION:
    ----------
    - The sorted word list secretly encodes character ordering rules:
      comparing two ADJACENT words, the first position where they
      differ tells us "this character comes before that character" in
      the alien alphabet. This gives a directed graph of character
      precedence.
    - Once we have that graph, the alien alphabet order is just its
      topological sort -- this file uses Kahn's algorithm (BFS,
      indegree-based).

    STEPS:
    ----------
    1. Initialize indegree = 0 for every distinct character that
       appears.
    2. For each pair of adjacent words, find the first differing
       character and add a directed edge (earlier char -> later char);
       increment indegree. Special case: if word1 is longer than word2
       and word2 is a prefix of word1 (e.g. "abc" before "ab"), that's
       an invalid ordering -> return "".
    3. Kahn's algorithm: push all 0-indegree characters into the queue,
       repeatedly pop, append to result, decrement indegree of
       neighbors, pushing any that hit 0.
    4. If the result doesn't contain all characters, a cycle exists ->
       return "" (invalid ordering); otherwise return the result.

    VARIATIONS TO REMEMBER:
    ----------
    - This is Kahn's (BFS, indegree-based) topo sort, not the DFS+stack
      version.
    - Same "compare adjacent items to build a precedence graph, then
      topo sort" pattern shows up in Course-Schedule-style ordering
      problems.

    TIME COMPLEXITY  : O(N*L + V+E) -> N words of length L to build the
                        graph, plus topo sort
    SPACE COMPLEXITY : O(V + E) -> adjacency list + indegree map
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;  // adjacency list
        unordered_map<char, int> indegree;      // indegree count for BFS

        // Step 1: Initialize indegree for every character (even isolated ones)
        for (auto &w : words) {
            for (char c : w) {
                indegree[c] = 0;
            }
        }

        // Step 2: Build graph by comparing adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            // Invalid case: ["abc", "ab"] → no valid ordering
            if (w1.size() > w2.size() && w1.find(w2) == 0)
                return "";

            // Compare character by character
            int len = min(w1.size(), w2.size());
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    break;  // only first different character matters!
                }
            }
        }

        // Step 3: BFS (Kahn's Algorithm for Topological Sort)
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0)    // all chars with 0 indegree
                q.push(p.first);
        }

        string result = "";
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            result += c;

            for (char next : adj[c]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // Step 4: If result length differs, a cycle exists → return ""
        if (result.size() != indegree.size())
            return "";

        return result;
    }
};


int main()
{
    

    return 0;
}