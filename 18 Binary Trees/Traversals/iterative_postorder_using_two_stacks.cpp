/*
    ============================================================
    TOPIC   : Binary Trees - Traversals
    PROBLEM : Postorder Traversal (Iterative, using two stacks)
    ============================================================

    INTUITION:
    ----------
    - Iterative approach: postorder (Left -> Right -> Root) is
      awkward to do directly with one stack, so instead compute a
      REVERSED postorder using a modified preorder, then reverse it.
    - Modified preorder here visits Root -> Right -> Left (note:
      right pushed before left, opposite of normal preorder), which
      when reversed gives exactly Left -> Right -> Root (postorder).
    - st1 does the Root->Right->Left traversal; st2 collects nodes
      in that order, and popping st2 at the end naturally reverses it.

    STEPS:
    ----------
    1. Push root onto st1.
    2. While st1 not empty: pop node from st1, push it onto st2.
    3. Push node's LEFT child onto st1 first, then RIGHT child
       (so right gets popped/processed before left — reversed order).
    4. After st1 is empty, st2 holds nodes in reverse-postorder.
    5. Pop everything from st2 into the result -> gives true postorder.

    VARIATIONS TO REMEMBER:
    ----------
    - Iterative preorder -> single stack, push right then left,
      visit on pop (Root -> Left -> Right, no reversal needed).
    - Iterative inorder -> push left children until null, pop+visit,
      then move right.
    - Recursive postorder -> just recurse left, recurse right, then
      visit — much simpler, no stack tricks needed.

    TIME COMPLEXITY  : O(n) -> each node processed a constant number
                        of times across both stacks
    SPACE COMPLEXITY : O(n) -> two stacks can together hold up to n nodes
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;     // Value of the node
    Node* left;   // Pointer to the left child
    Node* right;  // Pointer to the right child

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to return the postOrder traversal of a binary tree using two stacks
vector<int> postOrder(Node* root) {
    vector<int> postorder;  // Vector to store the postorder traversal

    // If the tree is empty, return an empty traversal
    if (root == NULL) {
        return postorder;
    }

    // Two stacks for iterative traversal
    stack<Node*> st1, st2;

    // Push the root node onto the first stack
    st1.push(root);

    // Iterative traversal to populate st2 with nodes in postorder
    while (!st1.empty()) {
        // Get the top node from st1
        root = st1.top();
        st1.pop();

        // Push the node onto st2
        st2.push(root);

        // Push left child onto st1 if exists
        if (root->left != NULL) {
            st1.push(root->left);
        }

        // Push right child onto st1 if exists
        if (root->right != NULL) {
            st1.push(root->right);
        }
    }

    // Populate the postorder traversal vector by popping st2
    while (!st2.empty()) {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    // Return the postorder traversal
    return postorder;
}

// Function to print the elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the vector and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder traversal result
    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}