/*
    ============================================================
    TOPIC   : Stacks & Queues - Basic
    PROBLEM : Implement a Queue Using a Linked List
    ============================================================

    INTUITION:
    ----------
    - A linked list naturally supports O(1) insertion at the tail and
      O(1) removal from the head, which maps directly onto a queue's
      enqueue-at-rear / dequeue-at-front behavior — and unlike an array,
      there's no fixed capacity to worry about.

    STEPS:
    ----------
    1. Maintain two pointers: `front` (head of the list) and `rear`
       (tail of the list).
    2. enqueue: create a new node; if the queue was empty, front and
       rear both point to it; otherwise link the old rear's next to it
       and move rear forward.
    3. dequeue: if empty, report underflow. Otherwise save the front
       node, advance front to front->next (reset rear to null if the
       list becomes empty), then delete the old front node.
    4. peek: return front->data after an empty check.

    VARIATIONS TO REMEMBER:
    ----------
    - Queue using a fixed array (queue_using_array.cpp) is simpler but
      has a capacity limit and wastes space without wraparound.
    - A circular linked list queue avoids needing a separate rear
      pointer by having rear->next point back to front.

    TIME COMPLEXITY  : O(1) -> enqueue, dequeue, peek are all constant time
    SPACE COMPLEXITY : O(n) -> one node allocated per element currently in the queue
    ============================================================
*/

#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Queue class using linked list
class Queue {
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Add an element (enqueue)
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << x << endl;
    }

    // Remove an element (dequeue)
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue underflow!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    // Return the front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display all elements in queue
    void display() {
        Node* curr = front;
        cout << "Queue: ";
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Queue() {
        while (front)
            dequeue();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    return 0;
}
