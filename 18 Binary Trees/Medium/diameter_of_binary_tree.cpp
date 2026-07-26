/*
    ============================================================
    TOPIC   : Binary Trees - Medium
    PROBLEM : Diameter of Binary Tree
    ============================================================

    INTUITION:
    ----------
    - Diameter = longest path between any two nodes, measured in
      number of edges. This path may or may not pass through the root.
    - At any node, the longest path THROUGH that node = (height of
      left subtree) + (height of right subtree). Compute this at
      every node while also computing height, in one pass.

    STEPS:
    ----------
    1. helper(node, diameter&): if null, return 0 (height).
    2. Recurse to get left height and right height.
    3. Update diameter = max(diameter, left + right) — this checks
       the path passing through the current node.
    4. Return 1 + max(left, right) as this node's height upward.
    5. diameterOfBinaryTree() kicks off helper with diameter = 0.

    VARIATIONS TO REMEMBER:
    ----------
    - Same "compute height + update a global answer" pattern as
      max path sum and balanced tree check.
    - If diameter needed in nodes instead of edges, add 1 to final answer.

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
    int helper(TreeNode* root, int& diameter) {
        if (!root)
            return 0;

        int left = helper(root->left, diameter);
        int right = helper(root->right, diameter);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }
};

int main() {
    return 0;
}