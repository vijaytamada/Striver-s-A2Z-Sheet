/*
    ============================================================
    TOPIC   : Graphs - Topo Sort
    PROBLEM : Topological Sort using DFS + Stack
    ============================================================

    INTUITION:
    ----------
    - Run normal DFS; whenever exploring ALL of a node's neighbors is
      finished (i.e., about to backtrack from it), push it onto a
      stack. A node is only pushed after everything it depends on has
      already been pushed.
    - Popping the stack from top to bottom then gives a valid
      topological order.

    STEPS:
    ----------
    1. For every unvisited node, run dfs(node).
    2. Inside dfs: mark visited, recurse into every unvisited neighbor
       first, THEN push the current node onto the stack (post-order).
    3. After DFS finishes on all components, pop the stack completely
       into the result vector -- that's the topological order.

    VARIATIONS TO REMEMBER:
    ----------
    - This is the DFS+stack version of topo sort -- contrast with
      Kahn's BFS+indegree version in
      topo_sort_using_indegree_kahns_algo.cpp.
    - Only valid on a DAG (Directed Acyclic Graph); running it on a
      cyclic graph gives a meaningless order (no cycle check here).

    TIME COMPLEXITY  : O(V + E)
    SPACE COMPLEXITY : O(V) visited array + stack + recursion stack
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;

    for (int neigh : adj[node]) {
        if (!vis[neigh]) {
            dfs(neigh, adj, vis, st);
        }
    }

    // Push node to stack after exploring all neighbors
    st.push(node);
}

vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    stack<int> st;

    // Run DFS on all components
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    // Pop from stack to get topological order
    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
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

    vector<int> result = topoSort(n, adj);

    cout << "Topological Sort (DFS):\n";
    for (int x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}
