/*
    ============================================================
    TOPIC   : Stacks & Queues - Basic
    PROBLEM : Implement a Queue Using Stacks (LIFO structure simulating FIFO)
    ============================================================

    INTUITION:
    ----------
    - A stack reverses order (LIFO); reversing an already-reversed order
      restores the original order. So to make a queue (FIFO) out of
      stacks (LIFO), this version reverses the ENTIRE stack on every
      push so the oldest element always ends up on top, ready to pop
      first — making pop O(1) but push O(n).
    - (The reverse tradeoff — O(1) push, O(n) pop by reversing only on
      pop when a second stack is empty — is the more common two-stack
      queue variant, but this file always reverses on push.)

    STEPS:
    ----------
    1. push(x): move every element from `st` into `temp` (reversing
       their order), push x onto the now-empty `st`, then move
       everything back from `temp` onto `st` (reversing again) so x
       ends up at the very bottom... actually ends up ordered so the
       oldest element sits on top for O(1) pop.
    2. pop(): simply pop and return st.top() — the front of the queue
       is always at the top of `st`.
    3. peek(): return st.top() without removing it.
    4. empty(): return st.empty().

    VARIATIONS TO REMEMBER:
    ----------
    - Stack using queues (stack_using_queue.cpp) is the mirror problem.
    - The alternative two-stack queue design keeps push O(1) and only
      pays the O(n) reversal cost lazily during pop when the "output"
      stack is empty (amortized O(1) per operation overall).

    TIME COMPLEXITY  : O(n) push -> reverses the whole stack twice; O(1) pop/peek
    SPACE COMPLEXITY : O(n) -> the temporary stack holds up to n elements during push
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> st, temp;

    MyQueue() {}

    void push(int x) {
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        st.push(x);

        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
    }

    int pop() {
        int val = st.top();
        st.pop();
        return val;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    return 0;
}