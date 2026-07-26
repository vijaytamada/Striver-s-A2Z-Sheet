/*
    ============================================================
    TOPIC   : Graphs - Basics
    CONCEPT : Graph Representation - Adjacency List
    ============================================================

    WHAT & WHY:
    ----------
    - A graph can be stored as an adjacency list: for every vertex, keep
      a list of its directly connected neighbors.
    - Preferred over an adjacency matrix for sparse graphs -- uses
      O(V + E) space instead of O(V^2).

    KEY POINTS:
    ----------
    1. For an undirected edge (u, v): add v to adj[u] AND u to adj[v].
    2. For a directed edge (u -> v): only add v to adj[u].
    3. `vector<vector<int>> adj(n + 1)` is the common way to declare it
       in C++ when using 1-indexed vertices.
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    // adjacency list representation
    vector<vector<int>> adj(n + 1);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // print the adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int node : adj[i]) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
