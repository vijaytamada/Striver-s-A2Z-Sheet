/*
    ============================================================
    TOPIC   : Binary Search Trees - Medium & Hard
    PROBLEM : Floor in a BST (largest value <= key)
    ============================================================

    INTUITION:
    ----------
    - Use the BST property to search for the key while remembering
      the best "floor candidate" seen so far.
    - If current node's value equals key, that IS the floor
      (exact match, can't do better).
    - If current node's value > key, floor can't be here or in the
      right subtree (both too big) -> go left.
    - If current node's value <= key, this node is a POSSIBLE floor
      candidate — record it, then try going right to find something
      even closer (larger but still <= key).

    STEPS:
    ----------
    1. Initialize floor = -1 (not found).
    2. While root is not null:
       - If root->data == key, return it immediately (exact match).
       - If root->data < key, update floor = root->data (candidate),
         move right (look for a tighter/larger valid candidate).
       - Else (root->data > key), move left (this subtree too big).
    3. Return floor after the loop ends.

    VARIATIONS TO REMEMBER:
    ----------
    - "Ceiling in BST" -> mirror logic: track smallest value >= key,
      move right when too small, move left + record candidate when
      value >= key.

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
    int floorInBST(Node* root, int key) {
        int floor = -1;
        while (root) {
            if (root->data == key) {
                return root->data;
            }
            
            if (root->data < key) {
                floor = root->data;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return floor;
    }
};

int main() {
    return 0;
}