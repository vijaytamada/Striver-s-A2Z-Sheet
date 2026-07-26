/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS
    PROBLEM : Cycle Detection in Undirected Graph (using BFS)
    ============================================================

    INTUITION:
    ----------
    - In an undirected graph, hitting an already-visited node that is
      NOT your immediate parent means there's another path to reach it
      -- that's a cycle.
    - Track the parent alongside the node in the BFS queue to tell
      apart "going back to parent" (normal) from "hitting a visited
      node that isn't the parent" (cycle).

    STEPS:
    ----------
    1. Push {start, parent = -1} into the queue, mark visited.
    2. Pop {node, parent}; for each neighbor: if unvisited, mark it
       visited and push {neighbor, node}.
    3. If a neighbor is visited AND neighbor != parent, a cycle exists
       -> return true.
    4. Repeat for all components (graph may be disconnected).

    VARIATIONS TO REMEMBER:
    ----------
    - Same idea with DFS instead: pass parent through recursion instead
      of storing it in the queue (see dfs_cycle_detection_undir_graph.cpp).
    - Directed graphs need a different technique (path/recursion-stack
      marking) -- this parent trick does NOT work there.

    TIME COMPLEXITY  : O(V + E)
    SPACE COMPLEXITY : O(V) visited array + queue, O(V+E) adjacency list
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int start, vector<vector<int>>& adj, vector<bool>& vis) {
        queue<pair<int, int>> q;  // {node, parent}
        q.push({start, -1});
        vis[start] = true;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (auto nb : adj[node]) {
                if (!vis[nb]) {
                    vis[nb] = true;
                    q.push({nb, node});
                }
                // If neighbor is visited and not the parent, cycle exists
                else if (nb != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(V, false);

        // Graph may be disconnected, so check all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(i, adj, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};  // cycle
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}};          // no cycle

    cout << sol.isCycle(3, edges1) << "\n";  // Output: 1 (true)
    cout << sol.isCycle(3, edges2) << "\n";  // Output: 0 (false)

    return 0;
}