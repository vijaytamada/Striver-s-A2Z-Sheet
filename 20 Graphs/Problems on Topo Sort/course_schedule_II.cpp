/*
    ============================================================
    TOPIC   : Graphs - Topo Sort
    PROBLEM : Course Schedule II (return a valid course order)
    ============================================================

    INTUITION:
    ----------
    - Exactly the same setup as Course Schedule I, but instead of just
      checking feasibility, we collect the actual topological order
      (Kahn's BFS, indegree-based) as the answer.

    STEPS:
    ----------
    1. Build adjacency list (b -> a for prerequisite [a, b]) and
       compute indegree.
    2. Push all 0-indegree nodes into the queue.
    3. Pop each node, append to the result list, decrement neighbors'
       indegree, push any that hit 0.
    4. If result.size() == numCourses, return it (valid order);
       otherwise return an empty vector (cycle -> impossible).

    VARIATIONS TO REMEMBER:
    ----------
    - Identical core logic to course_schedule.cpp -- that one only
      needs a boolean, this one needs the actual sequence.

    TIME COMPLEXITY  : O(V + E)
    SPACE COMPLEXITY : O(V + E) -> adjacency list + indegree array + result
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph and indegree
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto nb : adj[node]) {
                indegree[nb]--;
                if (indegree[nb] == 0)
                    q.push(nb);
            }
        }

        return res.size() == numCourses ? res : vector<int>();
    }
};

int main() {
    return 0;
}