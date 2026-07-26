/*
    ============================================================
    TOPIC   : Binary Trees - Medium
    PROBLEM : Binary Tree Maximum Path Sum
    ============================================================

    INTUITION:
    ----------
    - A "path" can start and end at any node, and may bend at most
      once (go up through a node from one child and down another).
    - At each node, two different things must be tracked:
      (a) the best path sum THROUGH this node (using both children) —
          used to update the global answer, since a path can only
          bend once so it can't be extended further up.
      (b) the best path sum EXTENDING upward from this node (using
          at most ONE child) — this is what gets returned to the
          parent, since the parent can only chain one side.
    - Negative subtree contributions are clamped to 0 (skip them —
      taking a negative branch only hurts the sum).

    STEPS:
    ----------
    1. helper(node, maxSum&): if null, return 0.
    2. left = max(0, helper(node->left, maxSum)) — clamp negatives.
    3. right = max(0, helper(node->right, maxSum)) — clamp negatives.
    4. Update maxSum = max(maxSum, left + right + node->val) — path
       bending at this node.
    5. Return node->val + max(left, right) — best single-branch path
       to hand up to the parent.
    6. maxPathSum() starts maxSum at INT_MIN and returns it after
       the recursion completes.

    VARIATIONS TO REMEMBER:
    ----------
    - Simpler version "max depth" only returns 1 + max(left, right)
      without the branching/global-max logic.
    - Similar "compute + update global answer in one pass" pattern
      as diameter of binary tree.

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
    int helper(TreeNode* root, int& maxSum) {
        if (!root)
            return 0;

        int left = max(0, helper(root->left, maxSum));
        int right = max(0, helper(root->right, maxSum));

        maxSum = max(maxSum, left + right + root->val);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
};

int main() {
    return 0;
}