/*
    ============================================================
    TOPIC   : Binary Trees - Traversals
    PROBLEM : Preorder Traversal (Recursive)
    ============================================================

    INTUITION:
    ----------
    - Recursive approach: mirrors the definition of preorder
      (Root -> Left -> Right) directly — visit the current node
      first, then recurse into left, then recurse into right.
    - The "visit" step (push to result) happens FIRST, before both
      recursive calls — this is what makes it "pre"-order.
    - Common use: copying/serializing a tree structure top-down.

    STEPS:
    ----------
    1. traversal(node, res): if node is null, return (base case).
    2. Push node->val into result first (visit before recursing).
    3. Recurse into node->left.
    4. Recurse into node->right.

    VARIATIONS TO REMEMBER:
    ----------
    - Iterative preorder -> use a stack, push right child then left
      child (so left pops first), visit on pop.
    - Inorder -> recurse left, visit, then recurse right.
    - Postorder -> recurse left, recurse right, then visit last.

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
    void traversal(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }

        res.push_back(root->val);

        traversal(root->left, res);
        traversal(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

int main() {
    return 0;
}