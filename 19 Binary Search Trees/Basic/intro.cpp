/*
    ============================================================
    TOPIC   : Binary Search Trees - Basic
    CONCEPT : Introduction - BST Node, Insert, Delete, Inorder
    ============================================================

    WHAT & WHY:
    ----------
    - Introduces the BST `Node` structure and the core operations
      every BST problem builds on: insert, delete, and inorder
      traversal (which yields sorted order for a BST).
    - `insertRecursion` / `insert` (iterative): place a new value by
      comparing at each node — go left if smaller, right if larger
      (or equal, here duplicates go right) — until an empty spot is found.
    - `delNode`: removing a node has 3 cases — no child (just delete),
      one child (replace node with its only child), two children
      (replace node's value with its inorder successor — the smallest
      value in its right subtree — then delete that successor node).

    KEY POINTS:
    ----------
    1. BST invariant: for every node, everything in its left subtree
       is smaller, everything in its right subtree is larger.
    2. Deletion's tricky case is two children — always swap with the
       inorder successor (or predecessor) and recursively delete that.
    3. Inorder traversal of a BST always produces values in ascending
       sorted order — a property used heavily in BST validation and
       kth-smallest/largest style problems.
    ============================================================
*/
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert into BST
Node* insertRecursion(Node* root, int val) {
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insertRecursion(root->left, val);
    else
        root->right = insertRecursion(root->right, val);

    return root;
}

// Insert into BST - iterative
Node* insert(Node* root, int key) {
    Node* temp = new Node(key);

    // If tree is empty
    if (root == nullptr) {
        return temp;
    }

    // Find the node who is going to
    // have the new node as its child
    Node* curr = root;
    while (curr != nullptr) {
        if (curr->data > key && curr->left != nullptr) {
            curr = curr->left;
        } else if (curr->data < key && curr->right != nullptr) {
            curr = curr->right;
        } else
            break;
    }

    // If key is smaller, make it left
    // child, else right child
    if (curr->data > key) {
        curr->left = temp;
    } else {
        curr->right = temp;
    }
    return root;
}

// Delete from BST
// Get inorder successor (smallest in right subtree)
Node* getSuccessor(Node* curr) {
    curr = curr->right;
    while (curr != nullptr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}

// Delete a node with value x from BST
Node* delNode(Node* root, int x) {
    if (root == nullptr)
        return root;

    if (root->data > x)
        root->left = delNode(root->left, x);
    else if (root->data < x)
        root->right = delNode(root->right, x);
    else {
        // Node with 0 or 1 child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with 2 children
        Node* succ = getSuccessor(root);
        root->data = succ->data;
        root->right = delNode(root->right, succ->data);
    }
    return root;
}

// In-order traversal (sorted order)
void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    // Demo insertions
    int values[] = {50, 30, 70, 20, 20, 40, 60, 80};
    for (int val : values)
        root = insertRecursion(root, val);

    cout << "In-order traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}