/*
    ============================================================
    TOPIC   : Binary Trees - Medium
    PROBLEM : Check if Two Binary Trees are Identical
    ============================================================

    INTUITION:
    ----------
    - Two trees are identical only if their root values match AND
      their left subtrees are identical AND their right subtrees
      are identical — a natural recursive definition.
    - Handle null cases first: both null -> identical here; only one
      null -> different structure, not identical.

    STEPS:
    ----------
    1. If both p and q are null, return true (matching empty subtrees).
    2. If exactly one is null, return false (structure mismatch).
    3. Otherwise, return true only if p->val == q->val AND
       isSameTree(p->left, q->left) AND isSameTree(p->right, q->right).

    VARIATIONS TO REMEMBER:
    ----------
    - "Symmetric Tree" -> same idea but compare p->left with q->right
      and p->right with q->left (mirror check).
    - "Subtree of Another Tree" -> run isSameTree at every node of
      the bigger tree.

    TIME COMPLEXITY  : O(min(n, m)) -> stops early on first mismatch
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are null, trees are identical here
        if (!p && !q)
            return true;

        // If one is null but not both, trees differ
        if (!p || !q)
            return false;

        // Values must match, and subtrees must match
        return (p->val == q->val) && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main() {
    return 0;
}