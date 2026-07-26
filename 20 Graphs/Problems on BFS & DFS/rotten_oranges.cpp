/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS (Grid problems)
    PROBLEM : Rotten Oranges
    ============================================================

    INTUITION:
    ----------
    - This is multi-source BFS on a grid (each cell = node, connected
      to its 4 neighbors): every rotten orange (2) rots its fresh
      neighbors after exactly 1 minute, and rot spreads outward level
      by level -- a perfect fit for BFS, where each "level" of the
      queue = one minute.

    STEPS:
    ----------
    1. Push all initially-rotten cells into the queue; count fresh
       oranges.
    2. If there are no fresh oranges, the answer is 0 immediately.
    3. BFS level by level: process everything currently in the queue
       (one full minute), rot any fresh neighbor, push it, decrement
       fresh count. Increment minutes after a level that changed
       something.
    4. At the end, if fresh_count is 0, return minutes; otherwise
       return -1 (some oranges could never rot).

    VARIATIONS TO REMEMBER:
    ----------
    - Same multi-source BFS idea as 01_matrix.cpp.
    - Classic mistake: incrementing minutes even for the last level
      that produces no new rot -- this code guards with
      `if (!q.empty()) minutes++` to avoid over-counting.

    TIME COMPLEXITY  : O(m*n) -> each cell processed once
    SPACE COMPLEXITY : O(m*n) -> queue in the worst case
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_count = 0;
        int minutes = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }

        if (fresh_count == 0) {
            return 0;
        }

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                pair<int, int> node = q.front();
                q.pop();

                int r = node.first;
                int c = node.second;

                for (const auto& d : dir) {
                    int nextR = r + d.first;
                    int nextC = c + d.second;

                    if (nextR >= 0 && nextR < rows && nextC >= 0 && nextC < cols && grid[nextR][nextC] == 1) {
                        grid[nextR][nextC] = 2;
                        q.push({nextR, nextC});
                        fresh_count--;
                    }
                }
            }

            if (!q.empty()) {
                minutes++;
            }
        }

        return fresh_count == 0 ? minutes : -1;
    }
};

int main() {
    return 0;
}