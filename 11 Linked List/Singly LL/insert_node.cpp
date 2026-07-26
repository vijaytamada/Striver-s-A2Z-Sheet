/*
    ============================================================
    TOPIC   : Linked List - Singly LL
    PROBLEM : Insert a Node into a Singly Linked List
    ============================================================

    INTUITION:
    ----------
    - Insertion means creating a new node and re-pointing the `next`
      references so the new node sits in the right spot in the chain.
    - Inserting at the head is O(1); inserting anywhere else needs to
      first walk to the node just before the target spot.

    STEPS:
    ----------
    1. Insert at end: walk to the last node, attach new node as its next.
    2. Insert at beginning: point new node's next at the old head, then
       update head to the new node.
    3. Insert at position: walk to the node just before the position,
       set new node's next to that node's next, then set that node's
       next to the new node.
    4. Handle the edge case where the position is beyond the list length.

    VARIATIONS TO REMEMBER:
    ----------
    - Doubly linked list insertion additionally needs to fix `prev`
      pointers on both neighboring nodes.
    - Insert into a sorted linked list keeping it sorted.

    TIME COMPLEXITY  : O(n) -> worst case (end/position) walks the list; O(1) for beginning
    SPACE COMPLEXITY : O(1) -> only the new node is allocated
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Singly Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Insert a node at the end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert a node at the beginning
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert a node at a specific position
void insertAtPosition(Node*& head, int val, int pos) {
    Node* newNode = new Node(val);
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        // Position greater than length — ignore
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);

    insertAtBeginning(head, 0);
    insertAtPosition(head, 1, 1);

    printList(head);

    return 0;
}
