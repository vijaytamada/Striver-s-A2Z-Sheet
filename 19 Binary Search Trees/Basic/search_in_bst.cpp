/*
    ============================================================
    TOPIC   : Binary Search Trees - Basic
    PROBLEM : Search in a Binary Search Tree
    ============================================================

    INTUITION:
    ----------
    - Use the BST property to eliminate half the tree at each step,
      just like binary search on a sorted array.
    - At each node: if it matches, found it. If the target is
      smaller, it can only be in the left subtree; if larger, only
      in the right subtree — no need to check the other side at all.

    STEPS:
    ----------
    1. If root is null, value doesn't exist -> return nullptr.
    2. If root->val == val, found it -> return root.
    3. If val < root->val, recurse into root->left.
    4. Else (val > root->val), recurse into root->right.

    VARIATIONS TO REMEMBER:
    ----------
    - Can be done iteratively too (just a while loop moving left/right)
      to save recursion stack space — O(1) extra space.
    - Same "eliminate one side" logic used in insert, floor, and
      ceiling in BST.

    TIME COMPLEXITY  : O(h) -> h = height of tree (follows one path down)
    SPACE COMPLEXITY : O(h) -> recursion stack
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == val) {
            return root;
        }

        if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};

int main() {
    return 0;
}