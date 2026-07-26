/*
    ============================================================
    TOPIC   : Stacks & Queues - Basic
    PROBLEM : Implement a Stack Using a Linked List
    ============================================================

    INTUITION:
    ----------
    - Inserting and removing at the HEAD of a linked list is O(1), which
      is exactly the LIFO behavior a stack needs — no capacity limit
      like a fixed array has.

    STEPS:
    ----------
    1. push: create a new node, point its next at the current head, then
       make it the new head.
    2. pop: if empty, report underflow. Otherwise save the head node,
       move head to head->next, then delete the old head.
    3. peek: return head->data after an empty check.

    VARIATIONS TO REMEMBER:
    ----------
    - Stack using a fixed array (stack_using_array.cpp) is simpler but
      has a capacity limit.
    - Stack using queues (stack_using_queue.cpp) simulates LIFO out of
      FIFO structures — one operation ends up O(n) instead of O(1).

    TIME COMPLEXITY  : O(1) -> push, pop, peek are all constant time
    SPACE COMPLEXITY : O(n) -> one node allocated per element currently on the stack
    ============================================================
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
    Node* head;

public:
    Stack() {
        head = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        cout << "Pushed: " << x << endl;
    }

    void pop() {
        if (head == nullptr) {
            cout << "Stack underflow!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Popped top element" << endl;
    }

    int peek() {
        if (head == nullptr) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return head->data;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Current Top: " << s.peek() << endl;
    s.pop();
    cout << "Current Top: " << s.peek() << endl;
    return 0;
}
