/*
    ============================================================
    TOPIC   : Stacks & Queues - Basic
    PROBLEM : Implement a Stack Using a Fixed-Size Array
    ============================================================

    INTUITION:
    ----------
    - A stack needs LIFO behavior, which a single `top` index into an
      array gives directly: push increments top and writes there, pop
      reads and decrements top — no shifting of other elements needed.

    STEPS:
    ----------
    1. push: if the array is full, reject. Otherwise increment top and
       store the value at arr[top].
    2. pop: if empty, reject. Otherwise return arr[top] and decrement top.
    3. peek: return arr[top] after an empty check.
    4. isEmpty: top == -1. isFull: top == capacity - 1.

    VARIATIONS TO REMEMBER:
    ----------
    - Stack using a linked list (stack_using_linked_list.cpp) removes
      the fixed capacity limit by pushing/popping at the head.
    - A dynamic array (like std::vector) can grow past MAX_SIZE by
      resizing (amortized O(1) push) instead of rejecting on overflow.

    TIME COMPLEXITY  : O(1) -> push, pop, peek are all constant time
    SPACE COMPLEXITY : O(n) -> fixed array of MAX_SIZE capacity
    ============================================================
*/

#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
    int* arr;
    int top;
    int capacity;

public:
    // Constructor to initialize the stack
    Stack() {
        arr = new int[MAX_SIZE];
        capacity = MAX_SIZE;
        top = -1;
    }
    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }
    // Add element to the stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
        cout << "Pushed: " << x << endl;
    }
    // Remove top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }
    // Get the value of the top element
    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        cout << "Stack is empty!" << endl;
        return -1;
    }
    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
    // Check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Top element after pop: " << s.peek() << endl;
    s.pop();
    s.pop();
    if (s.isEmpty())
        cout << "Stack is empty now." << endl;
    else
        cout << "Stack is not empty." << endl;
    return 0;
}
