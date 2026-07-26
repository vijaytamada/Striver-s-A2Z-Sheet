/*
    ============================================================
    TOPIC   : Graphs - Topo Sort
    PROBLEM : Topological Sort using Kahn's Algorithm (BFS, indegree-based)
    ============================================================

    Topo Sort Explaination - 

    INTUITION:
    ----------
    - A node can only appear in the topological order once all the
      nodes pointing to it have already appeared. "Indegree" (number
      of incoming edges) tracks how many prerequisites are still
      unmet -- a node with indegree 0 has no unmet prerequisites and is
      safe to place next.

    STEPS:
    ----------
    1. Compute indegree of every node from the adjacency list.
    2. Push all nodes with indegree 0 into the queue.
    3. Pop a node, add it to the topo order, then decrement the
       indegree of all its neighbors; if any neighbor's indegree drops
       to 0, push it.
    4. Repeat until the queue is empty; return the collected order.

    VARIATIONS TO REMEMBER:
    ----------
    - This is Kahn's (BFS, indegree-based) topo sort -- contrast with
      the DFS+stack version in topo_sort_using_stack.cpp.
    - Only works correctly (produces all V nodes) on a DAG; fewer than
      V nodes in the output means the graph has a cycle.

    TIME COMPLEXITY  : O(V + E)
    SPACE COMPLEXITY : O(V + E) -> adjacency list + indegree array + queue
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);

    // Compute indegree of each node
    for (int i = 0; i < n; i++) {
        for (int neigh : adj[i]) {
            indegree[neigh]++;
        }
    }

    queue<int> q;

    // Push all nodes with 0 indegree
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // Reduce indegree of neighbors
        for (int neigh : adj[node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0)
                q.push(neigh);
        }
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

    cout << "Topological Sort:\n";
    for (int x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}