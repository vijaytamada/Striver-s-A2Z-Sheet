/*
    ============================================================
    TOPIC   : Stacks & Queues - Basic
    PROBLEM : Implement a Stack Using Queues (FIFO structure simulating LIFO)
    ============================================================

    INTUITION:
    ----------
    - A queue preserves insertion order (FIFO), but a stack needs the
      newest element to come out first (LIFO). The trick: after pushing
      a new element into an empty helper queue, rotate every OLDER
      element behind it — that makes the newest element sit at the
      front of the queue, so it's the one that comes out on pop/top.
    - This makes push expensive (O(n), since it must rotate the whole
      queue) but pop/top cheap (O(1), just read the front).

    STEPS:
    ----------
    1. push(x): push x into `temp` first. Then drain all of `q` (the
       old elements) into `temp` behind x, preserving their relative
       order but placing x ahead of them.
    2. Swap `q` and `temp` so `q` now has x at the front.
    3. pop(): pop and return q.front() — the most recently pushed
       element is always at the front.
    4. top(): return q.front() without removing it.

    VARIATIONS TO REMEMBER:
    ----------
    - Queue using stacks (queue_using_stack.cpp) is the mirror problem.
    - An alternative design keeps push O(1) and instead pays the O(n)
      rotation cost during pop by rotating the queue (n-1) times to
      bring the last-pushed element to the front.

    TIME COMPLEXITY  : O(n) push -> rotates the whole queue behind the new element; O(1) pop/top
    SPACE COMPLEXITY : O(n) -> the temporary queue holds up to n elements during push
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q, temp;

    MyStack() {}

    void push(int x) {
        temp.push(x);

        while (!q.empty()) {
            temp.push(q.front());
            q.pop();
        }

        swap(q, temp);
    }

    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    return 0;
}