/*
    ============================================================
    TOPIC   : Binary Trees - Traversals
    PROBLEM : Preorder, Inorder, and Postorder in a Single Traversal
    ============================================================

    INTUITION:
    ----------
    - Instead of running 3 separate DFS passes, do ONE iterative DFS
      where each node is visited up to 3 times, using a "state" flag
      to know what stage we're at for that node.
    - Push (node, state) pairs onto a stack. state=1 means "about to
      process as preorder", state=2 means "about to process as
      inorder", state=3 means "about to process as postorder".
    - Each time a node is popped: record it into the right list based
      on its state, bump its state, push it back (except after state
      3, don't push back), and push the appropriate child for
      further processing.

    STEPS:
    ----------
    1. Push {root, 1} onto stack.
    2. Pop {node, state}.
    3. If state == 1: add node to `pre`, set state=2, push {node,2}
       back, then push {node->left, 1} if it exists (process left
       subtree fully before coming back to this node).
    4. If state == 2: add node to `in`, set state=3, push {node,3}
       back, then push {node->right, 1} if it exists.
    5. If state == 3: add node to `post` (no more pushing back for
       this node — it's fully processed).
    6. Repeat until stack is empty; return {pre, in, post}.

    VARIATIONS TO REMEMBER:
    ----------
    - Doing 3 separate traversals (recursive or iterative) is simpler
      to understand; this single-pass version is a space/time trick
      often asked about explicitly in interviews.

    TIME COMPLEXITY  : O(n) -> each node pushed/popped a constant
                        number of times (3 states)
    SPACE COMPLEXITY : O(n) -> stack plus the three result vectors
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Solution class containing the traversal function
class Solution {
public:
    // Function to get the Preorder,
    // Inorder and Postorder traversal
    // Of Binary Tree in One traversal
    vector<vector<int>> preInPostTraversal(Node* root) {
        // Vectors to store traversals
        vector<int> pre, in, post;

        // If the tree is empty,
        // return empty traversals
        if (root == NULL) {
            return {};
        }

        // Stack to maintain nodes
        // and their traversal state
        stack<pair<Node*, int>> st;

        // Start with the root node
        // and state 1 (preorder)
        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            // this is part of pre
            if (it.second == 1) {
                // Store the node's data
                // in the preorder traversal
                pre.push_back(it.first->data);
                // Move to state 2
                // (inorder) for this node
                it.second = 2;
                // Push the updated state
                // back onto the stack
                st.push(it);

                // Push left child onto
                // the stack for processing
                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }

            // this is a part of in
            else if (it.second == 2) {
                // Store the node's data
                // in the inorder traversal
                in.push_back(it.first->data);
                // Move to state 3
                // (postorder) for this node
                it.second = 3;
                // Push the updated state
                // back onto the stack
                st.push(it);

                // Push right child onto
                // the stack for processing
                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }

            // this is part of post
            else {
                // Store the node's data
                // in the postorder traversal
                post.push_back(it.first->data);
            }
        }

        // Returning the traversals
        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        return result;
    }
};

// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Create object of Solution class
    Solution sol;

    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = sol.preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}