/*
    ============================================================
    TOPIC   : Linked List - Doubly LL
    PROBLEM : Reverse a Doubly Linked List
    ============================================================

    INTUITION:
    ----------
    - In a doubly linked list every node already has both `next` and `prev`
      pointers — reversing just means swapping those two pointers on every
      node, then fixing the head to point at the old tail.

    STEPS:
    ----------
    1. Walk through the list one node at a time.
    2. For the current node, swap its `next` and `prev` pointers.
    3. Move to what is now the `prev` pointer (the old next) to continue.
    4. After the loop, the new head is the old tail — update head pointer.

    VARIATIONS TO REMEMBER:
    ----------
    - Reversing a singly linked list needs 3 pointers (prev, curr, next)
      since there's no `prev` field to reuse.
    - Reverse only a sublist [left, right] — same idea but bounded.

    TIME COMPLEXITY  : O(n) -> visit every node once
    SPACE COMPLEXITY : O(1) -> pointers only, no extra structure
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

// Function to reverse a doubly linked list
Node* reverseList(Node*& head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* curr = head;
    Node* temp = nullptr;

    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        head = curr;        // Update head to current node
        curr = curr->prev;  // Move to next node (which is prev before swap)
    }

    return head;
}

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    head = reverseList(head);
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}