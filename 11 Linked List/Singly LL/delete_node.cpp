/*
    ============================================================
    TOPIC   : Linked List - Singly LL
    PROBLEM : Delete a Node from a Singly Linked List
    ============================================================

    INTUITION:
    ----------
    - To remove a node, the node BEFORE it must be re-pointed to skip over
      it. Since there's no `prev` pointer, you must walk from head and
      keep a trailing reference to the previous node.

    STEPS:
    ----------
    1. Delete at beginning: move head to head->next, delete old head.
    2. Delete at end: walk until temp->next->next is nullptr (second-last
       node), delete temp->next, set temp->next to nullptr.
    3. Delete at position: walk to the node just before the position,
       skip over the target node by linking temp->next to temp->next->next.
    4. Handle edge cases: empty list, invalid position.

    VARIATIONS TO REMEMBER:
    ----------
    - Doubly linked list deletion is easier since `prev` already exists.
    - Delete a node given only a pointer to it (no head, no prev): copy
      the next node's data into it and delete the next node instead.

    TIME COMPLEXITY  : O(n) -> worst case (end/position) walks the list; O(1) for beginning
    SPACE COMPLEXITY : O(1) -> only pointers used, no extra structure
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

// Insert at end (for setup/demo)
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

// Delete node at beginning
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete node at end
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// Delete node at specific position
void deleteAtPosition(Node*& head, int pos) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (pos == 0) {
        deleteAtBeginning(head);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position!\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

// Print linked list
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

    // Create a list for demonstration
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Initial List: ";
    printList(head);

    deleteAtBeginning(head);
    cout << "After deleting at beginning: ";
    printList(head);

    deleteAtEnd(head);
    cout << "After deleting at end: ";
    printList(head);

    deleteAtPosition(head, 1);
    cout << "After deleting at position 1: ";
    printList(head);

    deleteAtPosition(head, 10);  // Invalid case
    cout << "After trying to delete invalid position: ";
    printList(head);

    return 0;
}
