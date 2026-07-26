/*
    ============================================================
    TOPIC   : Binary Search Trees - Basic
    PROBLEM : Find Minimum and Maximum Value in a BST
    ============================================================

    INTUITION:
    ----------
    - BST property: everything smaller than a node lies in its left
      subtree, everything larger lies in its right subtree.
    - So the minimum value is always the leftmost node (keep going
      left until there's no left child), and the maximum value is
      always the rightmost node (keep going right until no right child).
    - No need to check every node like in a plain binary tree.

    STEPS:
    ----------
    1. minValue(root): if root->left is null, this is the smallest
       node — return its data. Otherwise recurse left.
    2. maxValue(root): if root->right is null, this is the largest
       node — return its data. Otherwise recurse right.

    VARIATIONS TO REMEMBER:
    ----------
    - Same leftmost/rightmost idea is used to find the inorder
      successor/predecessor when deleting a BST node.
    - In a plain (non-BST) binary tree, you'd have to check every
      node — O(n) — since there's no ordering guarantee.

    TIME COMPLEXITY  : O(h) -> h = height of tree (follows one path down)
    SPACE COMPLEXITY : O(h) -> recursion stack
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int minValue(Node* root) {
        // code here
        if (root->left == nullptr) {
            return root->data;
        }

        return minValue(root->left);
    }

    int maxValue(Node* root) {
        // code here
        if (root->right == nullptr) {
            return root->data;
        }

        return maxValue(root->right);
    }
};

int main() {
    return 0;
}