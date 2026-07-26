/*
    ============================================================
    TOPIC   : Binary Trees - Traversals
    PROBLEM : Postorder Traversal (Recursive)
    ============================================================

    INTUITION:
    ----------
    - Recursive approach: mirrors the definition of postorder
      (Left -> Right -> Root) directly — recurse both children
      fully before visiting the current node.
    - The "visit" step (push to result) happens LAST, after both
      recursive calls — this is what makes it "post"-order.
    - Common use: deleting a tree bottom-up, or evaluating an
      expression tree (children before operator).

    STEPS:
    ----------
    1. traversal(node, res): if node is null, return (base case).
    2. Recurse into node->left first.
    3. Recurse into node->right second.
    4. Push node->val into result last (visit happens after both
       recursive calls return).

    VARIATIONS TO REMEMBER:
    ----------
    - Iterative postorder (two stacks) -> reverse of a modified
      preorder (Root -> Right -> Left).
    - Preorder -> visit first, then recurse left, then right.
    - Inorder -> recurse left, visit, then recurse right.

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
        traversal(root->right, res);

        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

int main() {
    return 0;
}