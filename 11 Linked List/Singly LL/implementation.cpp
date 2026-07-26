/*
    ============================================================
    TOPIC   : Linked List - Singly LL
    PROBLEM : Basic Singly Linked List Implementation
    ============================================================

    INTUITION:
    ----------
    - A singly linked list node stores data plus a single `next` pointer
      to the following node; the list is just a chain of these nodes
      starting from `head`.
    - This file manually wires up three nodes to show the basic
      structure and a forward traversal/print.

    STEPS:
    ----------
    1. Create the head node.
    2. Link head->next to a second node.
    3. Link second node's next to a third node.
    4. Traverse from head using `next` and print each node's data.

    VARIATIONS TO REMEMBER:
    ----------
    - Doubly linked list nodes additionally store a `prev` pointer.
    - Circular singly linked list: last node's next points back to head
      instead of being nullptr.

    TIME COMPLEXITY  : O(n) -> traversal visits every node once
    SPACE COMPLEXITY : O(1) -> no extra structure beyond the nodes themselves
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Singly Linked List Node
class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}