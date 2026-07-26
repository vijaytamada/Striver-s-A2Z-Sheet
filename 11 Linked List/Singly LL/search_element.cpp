/*
    ============================================================
    TOPIC   : Linked List - Singly LL
    PROBLEM : Search for an Element in a Singly Linked List
    ============================================================

    INTUITION:
    ----------
    - There's no random access (no indexing like an array), so the only
      way to check if a value exists is to walk node by node and compare.

    STEPS:
    ----------
    1. Start a pointer at head.
    2. While the pointer isn't null, compare its data to the key.
    3. If it matches, return true immediately.
    4. If the loop finishes without a match, return false.

    VARIATIONS TO REMEMBER:
    ----------
    - Return the index/position of the element instead of just true/false.
    - Search in a sorted linked list — still O(n), no binary search
      possible since there's no random access.

    TIME COMPLEXITY  : O(n) -> worst case checks every node once
    SPACE COMPLEXITY : O(1) -> just a traversal pointer
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

// Function to search for an element in the linked list
bool searchElement(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

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

    cout << "Linked List: ";
    printList(head);

    int key = 2;
    if (searchElement(head, key)) {
        cout << key << " found in the list." << endl;
    } else {
        cout << key << " not found in the list." << endl;
    }

    key = 5;
    if (searchElement(head, key)) {
        cout << key << " found in the list." << endl;
    } else {
        cout << key << " not found in the list." << endl;
    }

    return 0;
}