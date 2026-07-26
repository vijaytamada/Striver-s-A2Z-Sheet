/*
    ============================================================
    TOPIC   : Recursion - Basic
    PROBLEM : Sort a Stack (using only recursion, no extra array/stack)
    ============================================================

    INTUITION:
    ----------
    - Same "pop, recurse, reinsert" idea as reversing a stack: pop
      elements until empty, then as the recursion unwinds, insert each
      popped element back into its correct sorted position.
    - insertAtCorrectPosition itself recurses: it keeps popping while
      the top is bigger than the element being inserted, then pushes
      the element, then restores the popped elements on top.

    STEPS:
    ----------
    1. sortStack: if stack empty, return (base case).
    2. Otherwise pop the top element, recursively sort the rest of the
       stack, then insert the popped element at its correct sorted spot.
    3. insertAtCorrectPosition: if stack is empty or its top is <= the
       element, push the element directly.
    4. Otherwise pop the top, recurse to insert deeper, then push the
       popped element back on top.

    VARIATIONS TO REMEMBER:
    ----------
    - Reversing a stack recursively (reverse_a_stack.cpp) is the same
      pattern without the "correct position" comparison.
    - Sorting with an auxiliary stack (iterative, no recursion) is the
      more common O(n^2) alternative interviewers also ask for.

    TIME COMPLEXITY  : O(n^2) -> each of n elements triggers an O(n) insertion pass
    SPACE COMPLEXITY : O(n) -> recursion call stack holds up to n frames
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertAtCorrectPosition(stack<int>& s, int element) {
        // Base case: If stack is empty or the top element is less than or equal to the element
        if (s.empty() || s.top() <= element) {
            s.push(element);
            return;
        }

        // Remove the top element and recur
        int topElement = s.top();
        s.pop();
        insertAtCorrectPosition(s, element);

        // Put back the top element
        s.push(topElement);
    }

    void sortStack(stack<int>& s) {
        // Base case: If stack is empty
        if (s.empty())
            return;

        // Remove the top element and recur
        int topElement = s.top();
        s.pop();
        sortStack(s);

        // Insert the removed element at its correct position
        insertAtCorrectPosition(s, topElement);
    }
};

int main() {
    return 0;
}