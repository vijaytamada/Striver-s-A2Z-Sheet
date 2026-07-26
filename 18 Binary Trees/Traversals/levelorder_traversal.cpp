/*
    ============================================================
    TOPIC   : Binary Trees - Traversals
    PROBLEM : Level Order Traversal (BFS, level by level)
    ============================================================

    INTUITION:
    ----------
    - Unlike DFS-based traversals (pre/in/postorder), level order
      visits nodes breadth-first, one full depth level at a time.
    - Use a queue (BFS). The key trick to separate levels: capture
      `size = q.size()` at the start of each round — that many nodes
      belong to the current level, process exactly that many before
      moving to the next level.

    STEPS:
    ----------
    1. Push root into queue (if not null).
    2. While queue not empty: record size = q.size() (nodes in
       current level).
    3. Loop `size` times: pop front, add its value to current row,
       push its left and right children (if they exist) for the
       next level.
    4. Push completed row into result; repeat until queue is empty.

    VARIATIONS TO REMEMBER:
    ----------
    - "Zigzag Level Order" -> same BFS, alternate reversing each row.
    - "Right Side View" -> same BFS, just take the last element of
      each level's row.
    - DFS traversals (pre/in/post) use a stack or recursion instead
      of a queue, and go depth-first rather than level-by-level.

    TIME COMPLEXITY  : O(n) -> each node enqueued and dequeued once
    SPACE COMPLEXITY : O(n) -> queue can hold up to a full level's
                        worth of nodes (up to n/2 for a wide tree)
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> row;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                row.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            res.push_back(row);
        }

        return res;
    }
};

int main() {
    return 0;
}