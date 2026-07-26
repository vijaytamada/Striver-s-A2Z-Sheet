/*
    ============================================================
    TOPIC   : Graphs - BFS & DFS (Grid problems)
    PROBLEM : Surrounded Regions
    ============================================================

    INTUITION:
    ----------
    - Any 'O' connected (directly or indirectly) to the border can
      never be fully surrounded, so it must survive. Everything else
      gets flipped to 'X'.
    - Same "protect the boundary-connected region first" trick as
      no_of_enclaves: mark border-connected 'O's as safe ('S') before
      flipping.

    STEPS:
    ----------
    1. DFS flood-fill from every 'O' on the boundary, marking each one
       visited as 'S' (safe).
    2. Scan the whole board: any remaining 'O' (not reached from the
       border) gets flipped to 'X'.
    3. Scan again: convert all 'S' back to 'O' (restore the safe ones).

    VARIATIONS TO REMEMBER:
    ----------
    - Identical core idea to no_of_enclaves.cpp, just applied to
      characters instead of counting.
    - Grid treated as implicit graph, 4-directional neighbors.

    TIME COMPLEXITY  : O(m*n) -> boundary DFS + two full scans
    SPACE COMPLEXITY : O(m*n) -> recursion stack in the worst case
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        if (x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != 'O') {
            return;
        }

        board[x][y] = 'S';  // Mark as safe

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [dx, dy] : dirs) {
            dfs(x + dx, y + dy, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        int rows = board.size();
        int cols = board[0].size();

        // Step 1: Mark border-connected 'O's
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, board);
            dfs(i, cols - 1, board);
        }
        for (int j = 0; j < cols; j++) {
            dfs(0, j, board);
            dfs(rows - 1, j, board);
        }

        // Step 2: Flip surrounded 'O's to 'X'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        // Step 3: Restore safe cells
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main() {
    return 0;
}