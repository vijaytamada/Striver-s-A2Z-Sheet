/*
    ============================================================
    TOPIC   : Binary Trees - Medium
    PROBLEM : Check if a Binary Tree is Height-Balanced
    ============================================================

    INTUITION:
    ----------
    - A tree is balanced if, for every node, the height difference
      between its left and right subtree is at most 1 — and both
      subtrees are themselves balanced.
    - Naive approach recomputes height repeatedly (O(n^2)). Instead,
      compute height and check balance in the SAME recursive pass,
      using -1 as a sentinel meaning "already found unbalanced below".

    STEPS:
    ----------
    1. checkHeight(node): if null, return 0.
    2. Recurse left; if it returns -1, propagate -1 immediately
       (short-circuit — no point checking further).
    3. Recurse right; same short-circuit check.
    4. If |leftHeight - rightHeight| > 1, return -1 (unbalanced here).
    5. Otherwise return 1 + max(leftHeight, rightHeight) as normal height.
    6. isBalanced() = true if checkHeight(root) != -1.

    VARIATIONS TO REMEMBER:
    ----------
    - Classic "compute + validate in one pass" trick — reused in
      diameter of binary tree and max path sum problems.

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
    // Returns height if balanced, -1 if not balanced
    int checkHeight(TreeNode* root) {
        if (!root)
            return 0;

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1)
            return -1;  // left subtree not balanced

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1)
            return -1;  // right subtree not balanced

        if (abs(leftHeight - rightHeight) > 1)
            return -1;  // current node not balanced

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) { return checkHeight(root) != -1; }
};

int main() {
    return 0;
}