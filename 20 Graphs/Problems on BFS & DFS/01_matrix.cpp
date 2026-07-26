/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS (Grid problems)
    PROBLEM : 01 Matrix (distance to nearest 0)
    ============================================================

    INTUITION:
    ----------
    - Treat the grid as an implicit graph: each cell is a node connected
      to its 4 neighbors (up/down/left/right).
    - Instead of running BFS from every 1-cell to find the nearest 0
      (slow), do the reverse: start a BFS from ALL 0-cells at once
      (multi-source BFS). The first time a cell is reached gives its
      shortest distance to any 0.

    STEPS:
    ----------
    1. Push every cell with value 0 into the queue, mark visited, dist=0.
    2. BFS level by level; for each popped cell, look at its 4 neighbors.
    3. If a neighbor is unvisited, set dist = current dist + 1, mark
       visited, and push it.
    4. Continue until the queue is empty; return the dist matrix.

    VARIATIONS TO REMEMBER:
    ----------
    - Same multi-source BFS trick is used in Rotten Oranges.

    TIME COMPLEXITY  : O(m*n) -> every cell pushed and popped once
    SPACE COMPLEXITY : O(m*n) -> dist + visited matrices and the queue
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        // Step 1: Push all 0s into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;   // mark zero cells as visited
                    dist[i][j] = 0;  // distance to nearest 0 is 0
                }
            }
        }

        // BFS directions
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 3: BFS traversal
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (!vis[nx][ny]) {                 // not visited yet
                        vis[nx][ny] = 1;                // mark visited
                        dist[nx][ny] = dist[x][y] + 1;  // set distance
                        q.push({nx, ny});               // enqueue
                    }
                }
            }
        }

        return dist;
    }
};
int main() {
    return 0;
}