/*
    ============================================================
    TOPIC   : Binary Search Trees - Medium & Hard
    PROBLEM : Ceiling in a BST (smallest value >= key)
    ============================================================

    INTUITION:
    ----------
    - Use the BST property to search for the key while remembering
      the best "ceiling candidate" seen so far.
    - If current node's value equals key, that IS the ceiling
      (exact match, can't do better).
    - If current node's value < key, ceiling can't be here or in the
      left subtree (both too small) -> go right.
    - If current node's value >= key, this node is a POSSIBLE ceiling
      candidate — record it, then try going left to find something
      even closer (smaller but still >= key).

    STEPS:
    ----------
    1. Initialize ceil = -1 (not found).
    2. While root is not null:
       - If root->data == key, return it immediately (exact match).
       - If root->data < key, move right (this subtree too small).
       - Else, update ceil = root->data (candidate), move left
         (look for a tighter/smaller valid candidate).
    3. Return ceil after the loop ends.

    VARIATIONS TO REMEMBER:
    ----------
    - "Floor in BST" -> mirror logic: track largest value <= key,
      move left when too big, move right + record candidate when
      value <= key.

    TIME COMPLEXITY  : O(h) -> h = height of tree (single path down)
    SPACE COMPLEXITY : O(1) -> iterative, no recursion stack used
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
    int ceilInBST(Node* root, int key) {
        int ceil = -1;
        while (root) {
            if (root->data == key) {
                return root->data;
            }
            
            if (root->data < key) {
                root = root->right;
            } else {
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
    }
};

int main() {
    return 0;
}