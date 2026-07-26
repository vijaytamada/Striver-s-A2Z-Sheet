/*
    ============================================================
    TOPIC   : Linked List - Doubly LL
    PROBLEM : Insert a Node into a Doubly Linked List
    ============================================================

    INTUITION:
    ----------
    - Insertion just means creating a new node and rewiring the `next`
      and `prev` pointers of its neighbors to include it.
    - Because nodes have `prev`, you don't need to track "the node
      before" separately — you can read it straight off the target node.

    STEPS:
    ----------
    1. Insert at end: walk to the last node, attach new node as its
       next, and set new node's prev to the old last node.
    2. Insert at beginning: point new node's next at the old head, set
       old head's prev to new node, then update head.
    3. Insert at position: walk to the node just before the position,
       splice the new node in between it and its next, fixing both
       prev and next pointers on both sides.

    VARIATIONS TO REMEMBER:
    ----------
    - Singly linked list insertion only needs to fix `next` pointers.
    - Insert before/after a given node reference (no position index).

    TIME COMPLEXITY  : O(n) -> worst case (end/position) walks the list; O(1) for beginning
    SPACE COMPLEXITY : O(1) -> only the new node is allocated
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

// Insert a node at the end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }

        ptr->next = newNode;
        newNode->prev = ptr;
    }
}

// Insert a node at the beginning
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert a node at a specific position
void insertAtPosition(Node*& head, int val, int pos) {
    Node* newNode = new Node(val);

    if (pos == 0) {
        insertAtBeginning(head, val);
        return;
    }

    Node* ptr = head;
    for (int i = 0; i < pos - 1 && ptr != nullptr; i++) {
        ptr = ptr->next;
    }

    if (ptr == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }

    newNode->next = ptr->next;
    newNode->prev = ptr;

    if (ptr->next != nullptr) {
        ptr->next->prev = newNode;
    }

    ptr->next = newNode;
}

int main() {
    Node* head = nullptr;

    // Insert elements
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtBeginning(head, 0);
    insertAtPosition(head, 1, 1);

    // Print the list
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    return 0;
}