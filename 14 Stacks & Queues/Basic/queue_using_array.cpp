/*
    ============================================================
    TOPIC   : Stacks & Queues - Basic
    PROBLEM : Implement a Queue Using a Fixed-Size Array
    ============================================================

    INTUITION:
    ----------
    - A queue needs FIFO behavior, so keep two indices: `front` (where
      the next dequeue happens) and `rear` (where the next enqueue
      happens). Elements are added at the back and removed from the front.

    STEPS:
    ----------
    1. enqueue: if the array is full, reject. Otherwise, if this is the
       first element set front to 0, then increment rear and store the
       value there.
    2. dequeue: if empty, reject. Otherwise return arr[front] and
       increment front; if front passes rear, reset both to -1 (empty).
    3. getFront/getRear: just read arr[front]/arr[rear] after an empty check.
    4. isEmpty: true when front is -1 or front has overtaken rear.

    VARIATIONS TO REMEMBER:
    ----------
    - This simple version wastes array space as front advances (no
      wraparound) — a Circular Queue reuses that freed space using
      modulo arithmetic on the indices.
    - Queue using a linked list (queue_using_linked_list.cpp) avoids the
      fixed-size limitation entirely.

    TIME COMPLEXITY  : O(1) -> enqueue, dequeue, front, rear are all constant time
    SPACE COMPLEXITY : O(n) -> fixed array of MAX_SIZE capacity
    ============================================================
*/

#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
    int* arr;
    int front, rear;

public:
    Queue() {
        arr = new int[MAX_SIZE];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
            front = 0;
        arr[++rear] = val;
        cout << "Enqueued: " << val << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int val = arr[front++];
        if (front > rear)
            front = rear = -1;
        return val;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    q.enqueue(40);
    q.display();

    return 0;
}
