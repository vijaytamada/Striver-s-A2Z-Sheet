/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS (Grid problems)
    PROBLEM : Number of Enclaves
    ============================================================

    INTUITION:
    ----------
    - Land cells (1) connected to the boundary can "escape" the grid,
      so they don't count. Any land cell isolated from the border
      (surrounded by water on every reachable path) is an enclave.
    - Trick: run DFS flood-fill from every boundary cell that's land,
      turning all border-connected land into water (0). Whatever land
      (1) remains afterward is guaranteed enclosed.

    STEPS:
    ----------
    1. For every cell on the first/last row and first/last column, if
       it's land, DFS flood-fill it to water (sink it and everything
       connected to it).
    2. After this cleanup, scan the whole grid and count the remaining
       1s -- those are the enclaves.

    VARIATIONS TO REMEMBER:
    ----------
    - Same "sink the boundary-connected region first" trick is used in
      Surrounded Regions (there it marks 'O' as safe instead of sinking).
    - Grid treated as implicit graph, 4-directional (no diagonals).

    TIME COMPLEXITY  : O(m*n) -> boundary DFS + final scan
    SPACE COMPLEXITY : O(m*n) -> recursion stack in the worst case
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == 0) {
            return;
        }

        grid[x][y] = 0;  // mark visited as sea

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [dx, dy] : dirs) {
            dfs(x + dx, y + dy, grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Flood-fill from boundary
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, grid);
            dfs(i, cols - 1, grid);
        }
        for (int j = 0; j < cols; j++) {
            dfs(0, j, grid);
            dfs(rows - 1, j, grid);
        }

        // Count remaining land cells
        int res = 0;
        for (auto& row : grid) {
            for (int ele : row) {
                if (ele == 1) {  // FIXED: compare with integer 1
                    res++;
                }
            }
        }

        return res;
    }
};

int main() {
    return 0;
}