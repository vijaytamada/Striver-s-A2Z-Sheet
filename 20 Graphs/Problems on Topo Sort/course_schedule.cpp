/*
    ============================================================
    TOPIC   : Graphs - Topo Sort
    PROBLEM : Course Schedule (can all courses be finished?)
    ============================================================

    INTUITION:
    ----------
    - prerequisites[i] = [a, b] means "b must be taken before a", i.e.
      an edge b -> a. If every course can be scheduled, the graph has
      no cycle (a cycle would mean a course indirectly depends on
      itself).
    - Kahn's algorithm (BFS, indegree-based) naturally detects this: if
      we can topologically sort ALL nodes, there's no cycle.

    STEPS:
    ----------
    1. Build adjacency list (b -> a for each prerequisite pair) and
       compute indegree of each course.
    2. Push all 0-indegree courses into the queue.
    3. Pop, count it as processed, decrement indegree of its
       neighbors, push any that hit 0.
    4. If count of processed courses == numCourses, no cycle -> return
       true; else false.

    VARIATIONS TO REMEMBER:
    ----------
    - Course Schedule II asks for the actual order (see
      course_schedule_II.cpp) -- nearly identical code, just collect
      the order instead of only counting.
    - Same idea can be done with DFS + recursion-stack cycle detection
      instead of Kahn's BFS.

    TIME COMPLEXITY  : O(V + E)
    SPACE COMPLEXITY : O(V + E) -> adjacency list + indegree array + queue
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (auto nb : adj[node]) {
                indegree[nb]--;
                if (indegree[nb] == 0)
                    q.push(nb);
            }
        }

        return count == numCourses;
    }
};

int main() {
    return 0;
}