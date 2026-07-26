/*
    ============================================================
    TOPIC   : Binary Trees - Traversals
    PROBLEM : Inorder Traversal (Recursive)
    ============================================================

    INTUITION:
    ----------
    - Recursive approach: naturally mimics the definition of inorder
      (Left -> Root -> Right) — no manual stack needed, the call
      stack does the bookkeeping for us.
    - Fully recurse into the left subtree first, THEN visit (push)
      the current node, THEN recurse into the right subtree.
    - For a BST, this produces values in sorted ascending order.

    STEPS:
    ----------
    1. traversal(node, res): if node is null, return (base case).
    2. Recurse into node->left first.
    3. Push node->val into result (visit happens between the two
       recursive calls — that's what makes it "in-order").
    4. Recurse into node->right.

    VARIATIONS TO REMEMBER:
    ----------
    - Iterative inorder -> use an explicit stack: push all left
      children first, pop+visit, then move to the popped node's right.
    - Preorder -> visit before recursing (Root -> Left -> Right).
    - Postorder -> visit after both recursive calls (Left -> Right -> Root).

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

        traversal(root->left, res);

        res.push_back(root->val);

        traversal(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

int main() {
    return 0;
}