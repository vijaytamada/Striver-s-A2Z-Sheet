/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS
    PROBLEM : Cycle Detection in Undirected Graph (using DFS)
    ============================================================

    INTUITION:
    ----------
    - While doing DFS, pass along the parent of the current node. If we
      reach a node that's already visited and it's NOT the parent, we
      found a second path to it -> cycle.

    STEPS:
    ----------
    1. Call dfs(node, parent = -1).
    2. Mark node visited; for each neighbor: if unvisited, recurse with
       parent = node (propagate true if a cycle is found).
    3. If a neighbor is visited and != parent, cycle found -> return
       true.
    4. Repeat for every unvisited node (disconnected components).

    VARIATIONS TO REMEMBER:
    ----------
    - Same idea with BFS instead of recursion -- store {node, parent}
      pairs in the queue (see bfs_cycle_detection_undir_graph.cpp).
    - Do NOT use this parent trick for directed graphs -- use
      pathVis/recursion-stack marking instead.

    TIME COMPLEXITY  : O(V + E)
    SPACE COMPLEXITY : O(V) visited array + recursion stack, O(V+E) adj list
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (auto nb : adj[node]) {
            if (!vis[nb]) {
                if (dfs(nb, node, adj, vis)) {
                    return true;
                }
            }
            // If neighbor is visited and not the parent, cycle exists
            else if (nb != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(V, false);

        // Graph may be disconnected, so check all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    return 0;
}