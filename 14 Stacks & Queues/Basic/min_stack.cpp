/*
    ============================================================
    TOPIC   : Stacks & Queues - Basic
    PROBLEM : Min Stack (design a stack that supports getMin() in O(1))
    ============================================================

    INTUITION:
    ----------
    - A plain stack only gives you fast access to the top, not the
      minimum. Track the running minimum alongside every element so it
      can be looked up instantly, and so it correctly "un-tracks" itself
      when that minimum gets popped.
    - The optimal way to do this without a second stack of the same
      size scaling awkwardly is to store a (value, minSoFar) PAIR at
      each stack position — the minimum as of that push is baked in.

    STEPS:
    ----------
    1. (Not optimal) Keep a second stack `minStack` that only pushes a
       new value when it's <= the current minimum, and pops it off when
       it equals the value being popped from the main stack.
    2. (Optimal) On push, compute minEle = min(val, current top's
       stored min) and push the pair {val, minEle}.
    3. pop/top/getMin simply read or remove the top pair — no extra
       bookkeeping needed since the min is stored right there.

    VARIATIONS TO REMEMBER:
    ----------
    - Max Stack is the mirror problem — same idea, track running maximum.
    - Min Stack with O(1) space (no pair/extra stack) using a
      mathematical encoding trick (store a value that lets you recover
      both the actual value and previous min).

    TIME COMPLEXITY  : O(1) -> push, pop, top, getMin are all constant time
    SPACE COMPLEXITY : O(n) -> one extra min value stored per element
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

#include <stack>
using namespace std;

// O(N) time approach - not optimal - next version is O(1) time
class MinStack1 {
    stack<int> orig;
    stack<int> minStack;

public:
    MinStack1() {}

    void push(int val) {
        orig.push(val);

        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (orig.empty())
            return;
        int topVal = orig.top();
        orig.pop();

        if (!minStack.empty() && minStack.top() == topVal) {
            minStack.pop();
        }
    }

    int top() {
        return orig.top();
    }

    int getMin() {
        return minStack.top();
    }
};

// O(1) time approach - optimal
class MinStack {
public:
    stack<pair<int, int>> st;
    int minEle;

    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            minEle = val;
        } else {
            minEle = min(val, st.top().second);
        }

        st.push({val, minEle});
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    return 0;
}