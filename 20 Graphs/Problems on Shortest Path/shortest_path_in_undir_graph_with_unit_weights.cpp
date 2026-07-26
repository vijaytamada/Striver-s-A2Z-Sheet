/*
    ============================================================
    TOPIC   : Graphs - Shortest Path
    PROBLEM : Shortest Path in Undirected Graph with Unit Weights
    ============================================================

    INTUITION:
    ----------
    - When every edge has the same weight (1), plain BFS already gives
      the shortest path -- no need for Dijkstra/priority queue, since
      BFS naturally explores nodes in increasing order of number of
      edges.

    STEPS:
    ----------
    1. Build adjacency list (undirected).
    2. dist[] = infinity, dist[src] = 0, push src into the queue.
    3. BFS: for each neighbor, if dist[node] + 1 improves
       dist[neighbor], update it and push the neighbor.
    4. Continue till the queue is empty; return dist[].

    VARIATIONS TO REMEMBER:
    ----------
    - If weights vary, this simple BFS relaxation breaks down -- need
      Dijkstra instead (see dijkstras_algo files).

    TIME COMPLEXITY  : O(V + E) -> building the adjacency list + one BFS pass
    SPACE COMPLEXITY : O(V + E) -> adjacency list + dist array + queue
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src) {
        // code here
        vector<vector<int>> adj(V);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> dist(V, INT_MAX);

        queue<int> q;
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nb : adj[node]) {
                if (dist[node] + 1 < dist[nb]) {
                    dist[nb] = dist[node] + 1;
                    q.push(nb);
                }
            }
        }

        return dist;
    }
};

int main() {
    return 0;
}