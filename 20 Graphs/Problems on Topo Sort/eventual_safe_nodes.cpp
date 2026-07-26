/*
    ============================================================
    TOPIC   : Graphs - Topo Sort
    PROBLEM : Eventual Safe Nodes
    ============================================================

    INTUITION:
    ----------
    - A node is "safe" if every path starting from it eventually
      terminates (reaches a node with no outgoing edges) without ever
      hitting a cycle. So "unsafe" nodes are exactly those that lie on
      or lead into a cycle.
    - Use DFS with the same vis/pathVis (recursion-stack) cycle
      detection trick as directed-graph cycle detection: if a node
      finishes DFS without being part of any cycle, mark it safe.

    STEPS:
    ----------
    1. For every unvisited node, run dfs(node).
    2. Inside dfs: mark vis and pathVis; for each neighbor, if
       unvisited recurse (propagate cycle-found upward); if visited AND
       still in pathVis, a cycle is found -> return true (unsafe).
    3. If all neighbors are explored with no cycle found, backtrack
       pathVis to 0 and mark this node safe (check[node] = 1).
    4. Collect and return all nodes marked safe.

    VARIATIONS TO REMEMBER:
    ----------
    - This reuses "cycle detection in directed graph" (DFS + pathVis):
      any node that never triggers cycle detection is safe.
    - Could alternatively be solved with Kahn's algorithm on the
      REVERSED graph (nodes that get topologically sorted are safe) --
      good alternative to remember.

    TIME COMPLEXITY  : O(V + E)
    SPACE COMPLEXITY : O(V) vis/pathVis/check arrays + recursion stack
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// DFS function to detect cycle and mark safe/unsafe nodes
bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
         vector<int>& pathVis, vector<int>& check) {

    vis[node] = 1;
    pathVis[node] = 1;

    for (int neigh : adj[node]) {

        // If neighbour not visited, visit it
        if (!vis[neigh]) {
            if (dfs(neigh, adj, vis, pathVis, check)) {
                return true;    // cycle found → unsafe
            }
        }
        // If neighbour is visited and still in recursion stack → cycle
        else if (pathVis[neigh]) {
            return true;
        }
    }

    // If we reach here ⇒ no cycle from this node
    pathVis[node] = 0;   // backtrack
    check[node] = 1;     // mark as safe
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& adj, int n) {
    vector<int> vis(n, 0), pathVis(n, 0), check(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, pathVis, check);
        }
    }

    vector<int> safeNodes;
    for (int i = 0; i < n; i++) {
        if (check[i] == 1) {
            safeNodes.push_back(i);
        }
    }
    return safeNodes;
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

    vector<int> safe = eventualSafeNodes(adj, n);

    cout << "Eventual Safe Nodes:\n";
    for (int x : safe) cout << x << " ";
    cout << "\n";

    return 0;
}
