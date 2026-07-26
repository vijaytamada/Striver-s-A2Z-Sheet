/*
    ============================================================
    TOPIC   : Graphs - Shortest Path
    PROBLEM : Dijkstra's Algorithm (using Priority Queue / Min-Heap)
    ============================================================

    INTUITION:
    ----------
    - Greedily pick the unvisited node with the smallest known distance so
      far — once popped from the min-heap, that shortest distance is final
      (works only because all edge weights are non-negative).
    - Relax all neighbors of the popped node: if going through this node
      gives a shorter path, update and push the neighbor into the heap.

    STEPS:
    ----------
    1. dist[] = infinity for all nodes, dist[source] = 0.
    2. Push {0, source} into a min-priority-queue (sorted by distance).
    3. Pop the smallest {dist, node}; for every neighbor, if
       dist[node] + edgeWeight < dist[neighbor], update dist[neighbor]
       and push {newDist, neighbor}.
    4. Repeat until the heap is empty.

    VARIATIONS TO REMEMBER:
    ----------
    - Using a `set` instead of a priority_queue allows erasing stale
      entries, slightly more efficient in practice.
    - Doesn't work with negative edge weights -> use Bellman-Ford instead.
    - Unit-weight graph shortest path -> plain BFS is enough, no heap needed.

    TIME COMPLEXITY  : O((V + E) log V) -> each edge relax does a heap push/pop
    SPACE COMPLEXITY : O(V + E) -> adjacency list + distance array + heap
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});  // {distance, node}

        while (!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (distance > dist[node])
                continue;

            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int weight = neighbor.second;

                if (dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main() {
    return 0;
}