/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS
    PROBLEM : Cycle Detection in Directed Graph (using DFS)
    ============================================================

    INTUITION:
    ----------
    - In a directed graph, visiting an already-visited node isn't
      automatically a cycle (it could be a valid DAG path merging).
      A cycle only exists if we come back to a node that is still on
      the CURRENT DFS path (the recursion stack).
    - Use two arrays: vis[] (ever visited) and pathVis[] (visited in
      the current recursion path). Hitting a node with pathVis = 1
      means a back edge -> cycle.

    STEPS:
    ----------
    1. Mark node visited and pathVis = 1 (entering recursion).
    2. For each neighbor: if unvisited, recurse; if the recursion finds
       a cycle, propagate true upward.
    3. If a neighbor is visited AND pathVis[neighbor] == 1, cycle found
       -> return true.
    4. Before returning (leaving this node), reset pathVis[node] = 0
       (backtrack) since we're done exploring this path.

    VARIATIONS TO REMEMBER:
    ----------
    - Directed graph cycle check can also be done with Kahn's BFS: if
      topological sort can't include all nodes, a cycle exists (see
      cycle_detection_in_dir_graph_bfs.cpp).
    - Undirected graph cycle detection uses the simpler "parent" trick
      instead of pathVis.

    TIME COMPLEXITY  : O(V + E)
    SPACE COMPLEXITY : O(V) -> vis + pathVis arrays + recursion stack
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// DFS function to detect cycle
bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
    vis[node] = 1;      // mark visited
    pathVis[node] = 1;  // mark in current DFS path

    for (int neigh : adj[node]) {
        // If not visited, recurse
        if (!vis[neigh]) {
            if (dfs(neigh, adj, vis, pathVis))
                return true;  // cycle found
        }
        // If visited AND still in current path → cycle
        else if (pathVis[neigh]) {
            return true;
        }
    }

    pathVis[node] = 0;  // backtrack (remove from current path)
    return false;
}

bool hasCycle(vector<vector<int>>& adj, int n) {
    vector<int> vis(n, 0), pathVis(n, 0);

    // Graph may be disconnected
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, pathVis))
                return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of directed edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v) meaning u -> v:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (hasCycle(adj, n))
        cout << "Cycle Detected in Directed Graph.\n";
    else
        cout << "No Cycle Found.\n";

    return 0;
}
