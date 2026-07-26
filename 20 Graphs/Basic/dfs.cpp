/*
    ============================================================
    TOPIC   : Graphs - Basics
    PROBLEM : Depth First Search (DFS) Traversal
    ============================================================

    INTUITION:
    ----------
    - Go as deep as possible along one path before backtracking, using
      recursion (the call stack acts like an implicit stack).
    - Mark a node visited the moment you enter it, so it's never
      revisited even through a different path.

    STEPS:
    ----------
    1. Mark the current node visited, process it.
    2. For every unvisited neighbor, recursively call dfs on it.
    3. When there are no more unvisited neighbors, backtrack.
    4. Repeat for every unvisited node to handle disconnected components.

    VARIATIONS TO REMEMBER:
    ----------
    - DFS is the base technique for cycle detection, DFS+stack based
      topological sort, connected components, and flood fill.

    TIME COMPLEXITY  : O(V + E) -> every node and edge visited once
    SPACE COMPLEXITY : O(V) -> recursion stack + visited array (plus O(V+E) adj list)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
};

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<int>> adj(n + 1);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    Solution sol;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "DFS starting from node " << i << ": ";
            sol.dfs(i, adj, visited);
            cout << "\n";
        }
    }

    return 0;
}