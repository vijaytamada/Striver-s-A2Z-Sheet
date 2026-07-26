/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS
    PROBLEM : Number of Provinces (Connected Components)
    ============================================================

    INTUITION:
    ----------
    - isConnected is essentially an adjacency matrix. A "province" is
      just a connected component of the graph -- count how many
      separate components exist.
    - Standard "count connected components" pattern: for every
      unvisited node, run BFS/DFS to mark its entire component, and
      bump a counter once per component.

    STEPS:
    ----------
    1. Convert the isConnected matrix into an adjacency list.
    2. For each unvisited node, run BFS (or DFS) to visit its whole
       component, and increment the result count.
    3. Return the count after processing all nodes.

    VARIATIONS TO REMEMBER:
    ----------
    - This exact "count components via BFS/DFS" pattern reappears
      constantly -- islands problems, friend circles, etc.
    - File keeps both a dfs() and a bfs() helper; only bfs() is called
      (the dfs() call is commented out) -- either gives the same result.

    TIME COMPLEXITY  : O(V^2) -> building the adjacency list from the
                        n x n matrix dominates
    SPACE COMPLEXITY : O(V) visited + O(V^2) adjacency representation
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (auto nb : adj[node]) {
            if (!vis[nb]) {
                dfs(nb, adj, vis);
            }
        }
    }

    void bfs(int start, vector<vector<int>>& adj, vector<bool>& vis) {
        queue<int> q;

        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nb : adj[node]) {
                if (!vis[nb]) {
                    q.push(nb);
                    vis[nb] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, false);
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                // dfs(i, adj, vis);
                bfs(i, adj, vis);
                res++;
            }
        }

        return res;
    }
};

int main() {
    return 0;
}