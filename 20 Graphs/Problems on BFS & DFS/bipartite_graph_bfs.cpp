/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS
    PROBLEM : Check if Graph is Bipartite (using BFS)
    ============================================================

    INTUITION:
    ----------
    - A graph is bipartite if it can be colored with only 2 colors such
      that no two adjacent nodes share the same color.
    - BFS layer by layer, alternating the color of each neighbor
      relative to its parent. If a neighbor is already colored the SAME
      as the current node, bipartite-ness is broken.
    - Key fact: any graph containing an odd-length cycle can never be
      bipartite.

    STEPS:
    ----------
    1. color[] = -1 for all nodes (uncolored).
    2. For every uncolored node (handles disconnected components),
       start BFS and color it 0.
    3. For each neighbor: if uncolored, give it the opposite color and
       push to queue; if already colored the same as current, return
       false.
    4. If BFS finishes with no conflicts on all components, return true.

    VARIATIONS TO REMEMBER:
    ----------
    - Same logic with DFS coloring instead of BFS (see
      bipartite_graph_dfs.cpp).
    - Any graph with only even-length cycles (or no cycles) is bipartite.

    TIME COMPLEXITY  : O(V + E)
    SPACE COMPLEXITY : O(V) color array + queue, O(V+E) adjacency list
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if the graph is bipartite using BFS
bool isBipartite(vector<vector<int>>& adj, int n) {
    vector<int> color(n, -1);  // -1 = uncolored, 0/1 = two colors

    // Graph may be disconnected, so check each component
    for (int start = 0; start < n; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;  // Start coloring with 0

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neigh : adj[node]) {
                    // If uncolored, assign opposite color
                    if (color[neigh] == -1) {
                        color[neigh] = 1 - color[node];
                        q.push(neigh);
                    }
                    // If the neighbor has the same color ⇒ not bipartite
                    else if (color[neigh] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;  // No conflicts found
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
        adj[v].push_back(u);  // Undirected graph
    }

    if (isBipartite(adj, n))
        cout << "The graph is Bipartite.\n";
    else
        cout << "The graph is NOT Bipartite.\n";

    return 0;
}
