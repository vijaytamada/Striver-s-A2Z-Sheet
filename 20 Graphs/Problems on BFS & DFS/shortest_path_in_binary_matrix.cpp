/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS (Grid problems)
    PROBLEM : Shortest Path in Binary Matrix
    ============================================================

    INTUITION:
    ----------
    - Unweighted grid -> BFS gives the shortest path directly (each
      move costs 1 step). Here movement is allowed in all 8 directions
      (including diagonals), not just 4.

    STEPS:
    ----------
    1. If the start or end cell is blocked (1), return -1 immediately.
    2. Push (0,0) into the queue, mark it visited by setting
       grid[0][0] = 1, start pathLen = 1.
    3. BFS level by level (8 directions); if the destination cell is
       popped, return the current pathLen.
    4. For every valid, unvisited (0) neighbor, mark it visited and
       push it.
    5. Increment pathLen after finishing each level; if the queue
       empties without reaching the destination, return -1.

    VARIATIONS TO REMEMBER:
    ----------
    - Compare with 01_matrix / rotten_oranges which only use 4
      directions -- here it's 8 (king-move) directions.
    - Marking visited by mutating the grid in place avoids a separate
      visited matrix.

    TIME COMPLEXITY  : O(n^2) -> each cell visited once, 8 neighbors checked
    SPACE COMPLEXITY : O(n^2) -> queue in the worst case
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<vector<int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};

        queue<pair<int, int>> q;

        q.push({0, 0});
        grid[0][0] = 1;
        int pathLen = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            while (levelSize--) {
                auto [currX, currY] = q.front();
                q.pop();

                if (currX == n - 1 && currY == n - 1) {
                    return pathLen;
                }

                for (auto dir : dirs) {
                    int x = currX + dir[0];
                    int y = currY + dir[1];

                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1) {
                        continue;
                    }

                    grid[x][y] = 1;
                    q.push({x, y});
                }
            }

            pathLen++;
        }

        return -1;
    }
};

int main() {
    return 0;
}