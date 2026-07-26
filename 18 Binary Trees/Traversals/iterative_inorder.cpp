/*
    ============================================================
    TOPIC   : Binary Trees - Traversals
    PROBLEM : Inorder Traversal (Iterative, using explicit stack)
    ============================================================

    INTUITION:
    ----------
    - Iterative approach: manually simulate what recursion does using
      an explicit stack, since there's no call stack to rely on.
    - Core idea: keep pushing left children onto the stack until you
      hit null (going as far left as possible) — this defers visiting
      until we've reached the leftmost node.
    - Once you can't go left anymore, pop (visit) the node, then move
      to its right child and repeat the same "go left" process.

    STEPS:
    ----------
    1. Use `curr` starting at root, and a stack.
    2. Inner while: push curr and move curr = curr->left, until
       curr becomes null (all left ancestors are now on the stack).
    3. Pop the top of stack -> this is the next node to visit (in
       inorder sense); push its value into result.
    4. Move curr = popped node's right child, then repeat outer loop.
    5. Continue until curr is null AND stack is empty.

    VARIATIONS TO REMEMBER:
    ----------
    - Recursive inorder -> same Left->Root->Right idea, but the call
      stack handles it implicitly instead of an explicit stack.
    - Iterative preorder -> push right child then left child onto
      stack (so left is popped first), visit before pushing children.
    - Iterative postorder (two stacks) -> reverse of a modified
      preorder (Root->Right->Left), then reverse the result.

    TIME COMPLEXITY  : O(n) -> each node pushed and popped once
    SPACE COMPLEXITY : O(h) -> stack holds at most h nodes, h = height
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;                                                    // Value of the node
    TreeNode* left;                                             // Pointer to the left child
    TreeNode* right;                                            // Pointer to the right child
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // Constructor to initialize a node
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Step 1: Go left as far as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Step 2: Process node
            curr = st.top();
            st.pop();
            inorder.push_back(curr->val);

            // Step 3: Go right
            curr = curr->right;
        }

        return inorder;
    }
};

int main() {
    return 0;
}