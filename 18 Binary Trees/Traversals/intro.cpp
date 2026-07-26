/*
    ============================================================
    TOPIC   : Binary Trees - Traversals
    CONCEPT : Introduction - Binary Tree Node & Basic Preorder Print
    ============================================================

    WHAT & WHY:
    ----------
    - Introduces the basic `Node` structure (data, left, right) used
      throughout binary tree problems.
    - Shows a simple `insert` helper that builds a tree by comparing
      values (BST-style insert, used here just to build a sample tree).
    - Demonstrates the simplest traversal: recursive preorder
      (Root -> Left -> Right), just printing values as it visits them.

    KEY POINTS:
    ----------
    1. A tree node needs: a value + pointers to left and right children.
    2. Recursive traversal always follows the same shape: handle base
       case (null) first, then recurse left, recurse right, with the
       "visit" step placed depending on which traversal order is needed.
    3. This file is a starting point before diving into preorder,
       inorder, postorder, and level-order traversal variants
       (recursive and iterative) covered in this folder.
    ============================================================
*/
#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert nodes into the binary tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Preorder traversal (Root → Left → Right)
void preorder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = nullptr;

    // Insert sample nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}