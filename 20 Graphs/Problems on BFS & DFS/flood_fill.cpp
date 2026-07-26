/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS (Grid problems)
    PROBLEM : Flood Fill
    ============================================================

    INTUITION:
    ----------
    - Treat the image grid as an implicit graph: each cell connects to
      its 4 neighbors (up/down/left/right). Starting from (sr, sc),
      change every connected cell of the SAME original color to the
      new color -- exactly like the "bucket fill" tool in paint software.

    STEPS:
    ----------
    1. Save the original color at (sr, sc); if it already equals the
       new color, return early (avoids an infinite loop).
    2. Push (sr, sc) into the queue, recolor it immediately.
    3. For each popped cell, check its 4 neighbors; if a neighbor has
       the original color, recolor it and push it.
    4. Continue until the queue is empty.

    VARIATIONS TO REMEMBER:
    ----------
    - Same 4-directional grid-as-graph idea appears in rotten_oranges,
      01_matrix, no_of_enclaves, surrounded_region.
    - Could also be solved with DFS instead of BFS -- fill order doesn't
      matter here.

    TIME COMPLEXITY  : O(m*n) -> each cell visited once
    SPACE COMPLEXITY : O(m*n) -> queue in the worst case (all same color)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();

        int origColor = image[sr][sc];
        if (origColor == color)
            return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : dir) {
                int nr = r + d.first;
                int nc = c + d.second;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    image[nr][nc] == origColor) {
                    image[nr][nc] = color;
                    
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};

int main() {
    return 0;
}