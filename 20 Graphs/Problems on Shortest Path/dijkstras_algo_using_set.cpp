/*
    ============================================================
    TOPIC   : Graphs - Shortest Path
    PROBLEM : Dijkstra's Algorithm (using a Set)
    ============================================================

    INTUITION:
    ----------
    - Same greedy idea as the priority_queue version -- always expand
      the closest unvisited node -- but uses a set<pair<dist,node>>
      instead of a heap. A set stays sorted AND allows erasing a
      specific stale entry, so old (worse) distances can be actively
      removed instead of just left lying around.

    STEPS:
    ----------
    1. dist[] = infinity for all, dist[src] = 0. Insert {0, src} into
       the set.
    2. Take the smallest pair from the set (set.begin()), erase it.
    3. For every neighbor, if a shorter distance is found: erase the
       neighbor's OLD {dist, node} entry from the set (if it exists),
       update dist[], and insert the new {dist, node}.
    4. Repeat until the set is empty.

    VARIATIONS TO REMEMBER:
    ----------
    - The priority_queue version is simpler to write but can hold
      duplicate/stale entries (handled with a "skip if outdated" check
      instead of erasing) -- see dijkstras_algo_using_priority_queue.cpp.
    - Still doesn't work with negative weights -> use Bellman-Ford.

    TIME COMPLEXITY  : O(E log V) -> each edge relax does an erase+insert
    SPACE COMPLEXITY : O(V + E) -> adjacency list + distance array + set
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        set<pair<int, int>> st;  // {distance, node}
        st.insert({0, src});

        while (!st.empty()) {
            auto it = *st.begin();
            st.erase(st.begin());

            int node = it.second;
            int distance = it.first;

            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int weight = neighbor.second;

                if (distance + weight < dist[adjNode]) {
                    // erase old entry if exists
                    if (dist[adjNode] != INT_MAX) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    
                    dist[adjNode] = distance + weight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main() {
    return 0;
}