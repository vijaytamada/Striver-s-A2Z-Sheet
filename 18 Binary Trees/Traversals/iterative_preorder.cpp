/*
    ============================================================
    TOPIC   : Binary Trees - Traversals
    PROBLEM : Preorder Traversal (Iterative, using explicit stack)
    ============================================================

    INTUITION:
    ----------
    - Iterative approach: preorder (Root -> Left -> Right) is the
      easiest to do iteratively with a single stack, since we visit
      a node the moment we pop it — no need to defer/revisit like
      inorder or postorder require.
    - Push the RIGHT child before the LEFT child, so that when we
      pop, the LEFT child comes out first (matching Root->Left->Right
      order), since a stack is LIFO.

    STEPS:
    ----------
    1. Push root onto the stack.
    2. While stack not empty: pop node, visit it (add to result).
    3. Push node's right child first (if it exists).
    4. Push node's left child second (if it exists) — this ensures
       left is popped and processed before right on the next iterations.

    VARIATIONS TO REMEMBER:
    ----------
    - Recursive preorder -> visit node first, then recurse left,
      then recurse right; call stack does the work implicitly.
    - Iterative inorder -> push left children until null, then
      pop+visit, then move right (different pattern, defers visiting).
    - Iterative postorder (two stacks) -> reverse of Root->Right->Left.

    TIME COMPLEXITY  : O(n) -> each node pushed and popped once
    SPACE COMPLEXITY : O(h) -> stack holds at most h nodes, h = height
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;  // Value of the node
    TreeNode* left;  // Pointer to the left child
    TreeNode* right;  // Pointer to the right child
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // Constructor to initialize a node
};

class Solution {
public:
    // Function to perform preorder traversal of a binary tree iteratively
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;  // Vector to store the preorder traversal result
        
        // If the root is null, return an empty traversal result
        if(root == nullptr) {
            return preorder;
        }
        
        stack<TreeNode*> st;  // Stack to store nodes during traversal
        st.push(root);  // Push the root node onto the stack
        
        // Perform iterative preorder traversal
        while(!st.empty()) {
            root = st.top();  // Get the current node from the top of the stack
            st.pop();  // Remove the node from the stack
            
            preorder.push_back(root->val);  // Add the node's value to the preorder result
            
            // Push the right child onto the stack if exists
            if(root->right != nullptr) {
                st.push(root->right);
            }
            
            // Push the left child onto the stack if exists
            if(root->left != nullptr) {
                st.push(root->left);
            }
        }
        
        // Return the preorder traversal result
        return preorder;
    }
};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solution class
    Solution sol;

    // Getting the preorder traversal
    vector<int> result = sol.preorderTraversal(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}