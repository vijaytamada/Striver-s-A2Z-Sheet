/*
    ============================================================
    TOPIC   : Graphs - Basics
    PROBLEM : Breadth First Search (BFS) Traversal
    ============================================================

    INTUITION:
    ----------
    - Explore the graph level by level using a queue -- visit a node,
      then push all its unvisited neighbors before going any deeper.
    - Guarantees the shortest path (in number of edges) for unweighted
      graphs, since nodes are discovered in increasing distance order.

    STEPS:
    ----------
    1. Push the start node into the queue, mark it visited.
    2. Pop the front node, process/print it.
    3. Push all its unvisited neighbors into the queue and mark them
       visited immediately (before they're popped) to avoid duplicates.
    4. Repeat until the queue is empty; repeat for every unvisited node
       to also handle disconnected components.

    VARIATIONS TO REMEMBER:
    ----------
    - BFS gives shortest path in unweighted graphs, unit-weight shortest
      path, multi-source BFS (01 Matrix, Rotten Oranges).
    - Also used for cycle detection and bipartite checking.

    TIME COMPLEXITY  : O(V + E) -> every node and edge visited once
    SPACE COMPLEXITY : O(V) -> visited array + queue (plus O(V+E) adj list)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop(); 

            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
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
            cout << "BFS starting from node " << i << ": ";
            sol.bfs(i, adj, visited);
            cout << "\n";
        }
    }

    return 0;
}