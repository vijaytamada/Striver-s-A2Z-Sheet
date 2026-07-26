/*
    ============================================================
    TOPIC   : Graphs - Shortest Path
    PROBLEM : Cheapest Flights Within K Stops
    ============================================================

    INTUITION:
    ----------
    - Plain Dijkstra doesn't directly work here because the constraint
      is on the NUMBER OF STOPS (edges used), not purely on cost -- a
      cheaper path using more stops than allowed must be discarded. So
      instead of a priority queue sorted by cost, do a BFS level by
      level, where each level = one additional flight, and stop after
      k+1 levels (k stops = k+1 edges).

    STEPS:
    ----------
    1. Build adjacency list of {destination, price}.
    2. Push {src, cost = 0} into the queue; dist[src] = 0.
    3. Process the queue level by level (each level = one more flight
       taken); for every edge, relax dist[] if a cheaper cost is
       found, and push the neighbor for the next level.
    4. Stop after processing k+1 levels (stops <= k).
    5. Return dist[dst], or -1 if unreachable within the limit.

    VARIATIONS TO REMEMBER:
    ----------
    - This is a BFS-relaxation hybrid, different from plain Dijkstra --
      it deliberately allows re-pushing an already-relaxed node as long
      as it respects the stop limit; Dijkstra would just skip it.
    - Bellman-Ford limited to k+1 iterations is an equally valid way to
      solve this.

    TIME COMPLEXITY  : O(k * E) -> up to k+1 levels, each scanning all edges
    SPACE COMPLEXITY : O(V) dist array + O(V+E) adjacency list
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;  // {node, cost}

        q.push({src, 0});
        dist[src] = 0;

        int stops = 0;

        while (!q.empty() && stops <= k) {
            int size = q.size();

            while (size--) {
                auto [node, cost] = q.front();
                q.pop();

                for (auto& it : adj[node]) {
                    int nb = it.first;
                    int price = it.second;

                    if (cost + price < dist[nb]) {
                        dist[nb] = cost + price;
                        q.push({nb, dist[nb]});
                    }
                }
            }

            stops++;
            if (stops > k) {
                break;
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    return 0;
}