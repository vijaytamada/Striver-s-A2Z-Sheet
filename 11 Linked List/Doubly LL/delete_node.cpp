/*
    ============================================================
    TOPIC   : Linked List - Doubly LL
    PROBLEM : Delete a Node from a Doubly Linked List
    ============================================================

    INTUITION:
    ----------
    - Because every node stores both `next` and `prev`, deleting a node is
      just re-linking its neighbors to skip over it — no need to walk from
      head to find the previous node like in a singly linked list.

    STEPS:
    ----------
    1. Delete from beginning: move head to head->next, clear new head's prev.
    2. Delete from end: walk to the last node, then set second-last node's
       next to nullptr.
    3. Delete from position: walk to the target node, connect its prev's
       next to its next, and (if it exists) its next's prev to its prev.
    4. Always free the removed node's memory.

    VARIATIONS TO REMEMBER:
    ----------
    - Deleting from a singly linked list needs a trailing pointer since
      there is no `prev` field to jump back with.
    - Deleting a node given only a pointer to it (no head) is a classic
      trick: copy next node's data into current, then delete the next node.

    TIME COMPLEXITY  : O(n) -> worst case (end/position) walks the list; O(1) for beginning
    SPACE COMPLEXITY : O(1) -> only pointers used, no extra structure
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

// Delete a node from the end
void deleteNodeFromBeginning(Node*& head) {
    if (head == nullptr)
        return;

    Node* toDelete = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete toDelete;
}

// Delete a node from end
void deleteNodeFromEnd(Node*& head) {
    if (head == nullptr)
        return;

    Node* ptr = head;

    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }

    ptr->prev->next = nullptr;
    delete ptr;
}

// Delete a node from specific position
void deleteNodeFromPosition(Node*& head, int pos) {
    if (pos == 0) {
        deleteNodeFromBeginning(head);
        return;
    }

    Node* ptr = head;
    for (int i = 0; i < pos && ptr != nullptr; i++) {
        ptr = ptr->next;
    }

    if (ptr == nullptr)
        return;

    ptr->prev->next = ptr->next;

    if (ptr->next != nullptr)
        ptr->next->prev = ptr->prev;

    delete ptr;
}

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    deleteNodeFromPosition(head, 1);
    deleteNodeFromBeginning(head);
    deleteNodeFromEnd(head);
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}