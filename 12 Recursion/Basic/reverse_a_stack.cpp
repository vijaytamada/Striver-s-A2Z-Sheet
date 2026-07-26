/*
    ============================================================
    TOPIC   : Recursion - Basic
    PROBLEM : Reverse a Stack (using only recursion, no extra stack/array)
    ============================================================

    INTUITION:
    ----------
    - Recursion's call stack itself can act as temporary storage — pop
      elements one at a time until the stack is empty, then re-insert
      each one at the very bottom on the way back up the recursion.
    - Two helper recursions are needed: one to peel off elements top to
      bottom, another (insertAtBottom) to push a single element all the
      way to the bottom of what remains.

    STEPS:
    ----------
    1. reverseStack: if stack is empty, return (base case).
    2. Otherwise pop the top element, recursively reverse the rest of
       the stack, then insert the popped element at the bottom.
    3. insertAtBottom: if stack is empty, push the element (it's now at
       the bottom). Otherwise pop the top, recurse to insert deeper,
       then push the popped element back on top.

    VARIATIONS TO REMEMBER:
    ----------
    - Sorting a stack using recursion (sort_a_stack.cpp) uses the same
      "pop, recurse, insert at correct spot" pattern.
    - Reversing a queue using recursion follows a similar peel-and-rebuild idea.

    TIME COMPLEXITY  : O(n^2) -> each of n elements triggers an O(n) insertAtBottom
    SPACE COMPLEXITY : O(n) -> recursion call stack holds up to n frames
    ============================================================
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseStack(stack<int> &st) {
        if (st.empty()) {
            return;
        }

        int topElement = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, topElement);
    }

    void insertAtBottom(stack<int> &st, int ele) {
        if (st.empty()) {
            st.push(ele);
            return;
        }

        int topElement = st.top();
        st.pop();
        insertAtBottom(st, ele);
        st.push(topElement);
    }
};

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    Solution sol;
    sol.reverseStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}