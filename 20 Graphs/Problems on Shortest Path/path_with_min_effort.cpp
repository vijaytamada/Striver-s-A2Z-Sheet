/*
    ============================================================
    TOPIC   : Graphs - Shortest Path
    PROBLEM : Path With Minimum Effort
    ============================================================

    INTUITION:
    ----------
    - "Effort" of a path = the MAXIMUM absolute height difference along
      any single step of that path (not the sum). We want the path from
      top-left to bottom-right that minimizes this maximum step.
    - This is a Dijkstra variant: instead of adding edge weights, take
      max(currentEffort, edgeCost) when relaxing, since effort is
      defined by the worst single step, not cumulative cost.

    STEPS:
    ----------
    1. Grid treated as implicit graph, each cell connects to its 4
       neighbors.
    2. effort[][] = infinity, priority queue ordered by effort,
       starting {0, (0,0)}.
    3. Pop the cell with smallest effort so far; if it's the
       destination, return its effort (Dijkstra guarantees this is
       optimal once popped).
    4. For each neighbor, compute edgeCost = |height difference|,
       newEffort = max(currEffort, edgeCost); if newEffort improves the
       neighbor's stored effort, update and push.

    VARIATIONS TO REMEMBER:
    ----------
    - This "max instead of sum" relaxation trick also applies to
      bottleneck shortest path problems (minimize the maximum edge
      weight on a path).

    TIME COMPLEXITY  : O(m*n*log(m*n)) -> Dijkstra-style on a grid graph
    SPACE COMPLEXITY : O(m*n) -> effort matrix + priority queue
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, pair<int, int>>  // {effort, {x, y}}

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, {0, 0}});
        effort[0][0] = 0;

        while (!pq.empty()) {
            auto [currEffort, cell] = pq.top();
            pq.pop();

            int x = cell.first;
            int y = cell.second;

            // If reached destination
            if (x == rows - 1 && y == cols - 1)
                return currEffort;

            // Skip outdated state
            if (currEffort > effort[x][y])
                continue;

            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= rows || ny >= cols)
                    continue;

                int edgeCost = abs(heights[nx][ny] - heights[x][y]);
                int newEffort = max(currEffort, edgeCost);

                if (newEffort < effort[nx][ny]) {
                    effort[nx][ny] = newEffort;
                    pq.push({newEffort, {nx, ny}});
                }
            }
        }

        return effort[rows - 1][cols - 1];
    }
};

int main() {
    return 0;
}