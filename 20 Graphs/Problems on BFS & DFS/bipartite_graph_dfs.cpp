/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS
    PROBLEM : Check if Graph is Bipartite (using DFS)
    ============================================================

    INTUITION:
    ----------
    - Same 2-coloring idea as the BFS version, but colors are assigned
      recursively while diving deep instead of level by level.
    - At each node, color its uncolored neighbors with the opposite
      color and recurse; if a neighbor already has the same color,
      it's not bipartite.

    STEPS:
    ----------
    1. color[] = -1 for all nodes.
    2. For every uncolored node, call dfs(node, color = 0).
    3. Inside dfs: color the current node, then for each neighbor --
       if uncolored, recurse with the opposite color (propagate false
       up if it fails); if already the same color as current, return
       false.
    4. If all components pass, the graph is bipartite.

    VARIATIONS TO REMEMBER:
    ----------
    - BFS version does the exact same thing level-by-level (see
      bipartite_graph_bfs.cpp) -- pick whichever is easier to code
      under pressure.
    - Bipartite check == graph has no odd-length cycle.

    TIME COMPLEXITY  : O(V + E)
    SPACE COMPLEXITY : O(V) color array + recursion stack, O(V+E) adj list
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int currentColor, vector<int>& color, vector<vector<int>>& adj) {
    color[node] = currentColor;

    for (int neigh : adj[node]) {
        // If neighbor not colored, color with opposite color
        if (color[neigh] == -1) {
            if (!dfs(neigh, 1 - currentColor, color, adj))
                return false;
        }
        // If neighbor already has same color → not bipartite
        else if (color[neigh] == currentColor) {
            return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& adj, int n) {
    vector<int> color(n, -1);

    // Graph may be disconnected
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0, color, adj))
                return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected graph
    }

    if (isBipartite(adj, n))
        cout << "The graph is Bipartite.\n";
    else
        cout << "The graph is NOT Bipartite.\n";

    return 0;
}
