/*
    ============================================================
    TOPIC   : Binary Trees - Medium
    PROBLEM : Maximum Depth / Height of Binary Tree
    ============================================================

    INTUITION:
    ----------
    - Height of a tree = 1 + max height of its two subtrees.
    - An empty (null) node contributes 0 height — base case.
    - This is the simplest recursive pattern, and the base building
      block for many other tree problems (balanced check, diameter,
      max path sum all reuse this idea).

    STEPS:
    ----------
    1. If root is null, return 0.
    2. Recursively compute leftHeight = maxDepth(root->left).
    3. Recursively compute rightHeight = maxDepth(root->right).
    4. Return 1 + max(leftHeight, rightHeight).

    VARIATIONS TO REMEMBER:
    ----------
    - Minimum depth is trickier: must reach an actual leaf (not just
      any null), so handle one-sided subtrees specially.
    - This height computation is embedded inside diameter and
      balanced-tree solutions to avoid recomputation.

    TIME COMPLEXITY  : O(n) -> each node visited once
    SPACE COMPLEXITY : O(h) -> recursion stack, h = tree height
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    return 0;
}