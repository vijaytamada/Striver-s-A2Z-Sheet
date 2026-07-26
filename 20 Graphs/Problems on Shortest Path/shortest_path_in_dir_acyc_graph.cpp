/*
    ============================================================
    TOPIC   : Graphs - Shortest Path
    PROBLEM : Shortest Path in a Directed Acyclic Graph (DAG)
    ============================================================

    INTUITION:
    ----------
    - Since there are no cycles, we don't need Dijkstra at all -- just
      process nodes in TOPOLOGICAL ORDER and relax edges as we go. By
      the time a node is reached in topo order, all paths leading into
      it have already been considered, so its distance is final.
    - This works even with negative weights (unlike Dijkstra), because
      topological order guarantees no node is processed before all its
      predecessors.

    STEPS:
    ----------
    1. Build adjacency list of {neighbor, weight} and compute indegree
       of each node.
    2. Get topological order using Kahn's algorithm (BFS with indegree).
    3. dist[] = infinity, dist[src] = 0.
    4. Process nodes in topo order: for each node with a finite
       distance, relax all its outgoing edges
       (dist[v] = min(dist[v], dist[node] + weight)).
    5. Replace any remaining infinity with -1 (unreachable).

    VARIATIONS TO REMEMBER:
    ----------
    - Works with negative edge weights because of the DAG + topo-order
      guarantee -- this is the one shortest-path variant where negative
      weights are NOT a problem.
    - If the graph weren't a DAG: use Dijkstra (non-negative weights)
      or Bellman-Ford (negative weights allowed, detects negative
      cycles).

    TIME COMPLEXITY  : O(V + E) -> topo sort + one pass relaxing all edges
    SPACE COMPLEXITY : O(V + E) -> adjacency list + indegree + dist array
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        int src = 0;  // assuming source is 0, change if needed
        vector<int> inDegree(V, 0);
        vector<vector<pair<int, int>>> adj(V);

        // Build adjacency list
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            inDegree[v]++;
        }

        // Kahn's algorithm for topological sort
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto nb : adj[node]) {
                int v = nb.first;
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Relax edges in topological order
        for (int node : topo) {
            if (dist[node] != INT_MAX) {
                for (auto nb : adj[node]) {
                    int v = nb.first;
                    int wt = nb.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Replace unreachable nodes with -1
        for (auto& it : dist) {
            if (it == INT_MAX)
                it = -1;
        }

        return dist;
    }
};

int main() {
    return 0;
}