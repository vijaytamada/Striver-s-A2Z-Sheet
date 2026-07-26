/*
    ============================================================
    TOPIC   : Linked List - Doubly LL
    PROBLEM : Basic Doubly Linked List Implementation
    ============================================================

    INTUITION:
    ----------
    - A doubly linked list node stores a `next` pointer AND a `prev`
      pointer, so it can be traversed in both directions.
    - This file just wires up two nodes manually to show the basic
      structure and a forward traversal/print.

    STEPS:
    ----------
    1. Create the head node.
    2. Create the second node and link head->next to it.
    3. Link the second node's prev back to head.
    4. Traverse from head using `next` and print each node's data.

    VARIATIONS TO REMEMBER:
    ----------
    - Singly linked list nodes only have `next`, no `prev`.
    - Circular doubly linked list: tail->next points back to head, and
      head->prev points to tail.

    TIME COMPLEXITY  : O(n) -> traversal visits every node once
    SPACE COMPLEXITY : O(1) -> no extra structure beyond the nodes themselves
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}