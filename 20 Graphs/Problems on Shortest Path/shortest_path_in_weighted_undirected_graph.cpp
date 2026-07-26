/*
    ============================================================
    TOPIC   : Graphs - Shortest Path
    PROBLEM : Shortest Path in Weighted Undirected Graph (with path reconstruction)
    ============================================================

    INTUITION:
    ----------
    - Standard Dijkstra to find shortest distances, PLUS a parent[]
      array to reconstruct the actual path, not just its length.
    - parent[node] initially points to itself; whenever an edge is
      relaxed (a shorter path to `next` is found through `node`),
      update parent[next] = node. Walking parent[] backwards from the
      destination to the source rebuilds the path.

    STEPS:
    ----------
    1. Build weighted adjacency list; dist[] = infinity except
       dist[1] = 0 (source is node 1); parent[i] = i initially.
    2. Standard Dijkstra with a min-priority-queue: pop the smallest
       distance node, skip if outdated, relax neighbors and update
       parent[] on improvement.
    3. If dist[n] is still infinity, the destination is unreachable ->
       return {-1}.
    4. Reconstruct the path by walking parent[] from n back to 1 (stop
       when parent[cur] == cur), then reverse it.
    5. Return {total_weight, path nodes...}.

    VARIATIONS TO REMEMBER:
    ----------
    - The parent[] trick for path reconstruction applies to any
      shortest-path algorithm (Dijkstra, BFS, Bellman-Ford), not just
      this one.

    TIME COMPLEXITY  : O((V + E) log V) -> Dijkstra with priority queue
    SPACE COMPLEXITY : O(V + E) -> adjacency list + dist + parent + queue
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Adjacency list: node -> {neighbor, weight}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // Dijkstra setup
        vector<long long> dist(n + 1, LLONG_MAX);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto& it : adj[node]) {
                int next = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[next]) {
                    dist[next] = dist[node] + wt;
                    parent[next] = node;
                    pq.push({dist[next], next});
                }
            }
        }

        // If destination not reachable
        if (dist[n] == LLONG_MAX) {
            return {-1};
        }

        // Reconstruct path from n to 1
        vector<int> path;
        int cur = n;
        while (parent[cur] != cur) {
            path.push_back(cur);
            cur = parent[cur];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        // Final answer: {total_weight, path...}
        vector<int> ans;
        ans.push_back((int)dist[n]);
        for (int node : path)
            ans.push_back(node);

        return ans;
    }
};

int main() {
    return 0;
}