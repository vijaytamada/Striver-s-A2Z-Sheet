/*
    ============================================================
    TOPIC   : Linked List - Singly LL
    PROBLEM : Find the Length of a Singly Linked List
    ============================================================

    INTUITION:
    ----------
    - There's no size field, so the only way to know how many nodes exist
      is to walk the whole list once, counting as you go.

    STEPS:
    ----------
    1. Start a counter at 0 and a pointer at head.
    2. While the pointer isn't null, increment the counter and move to
       the next node.
    3. Return the counter once the pointer becomes null.

    VARIATIONS TO REMEMBER:
    ----------
    - Finding the middle node uses slow/fast pointers instead of first
      computing length.
    - Detecting a cycle (Floyd's algorithm) means this simple count would
      loop forever — need a visited check or slow/fast pointers instead.

    TIME COMPLEXITY  : O(n) -> visits every node once
    SPACE COMPLEXITY : O(1) -> just a counter variable
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

// Function to calculate the length of the linked list
int findLength(Node* head) {
    int len = 0;
    while (head != nullptr) {
        head = head->next;
        len++;
    }
    return len;
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
 
    
    cout << "Length of Linked List: " << findLength(head) << endl;

    cout << "Linked List: ";
    printList(head);

    return 0;
}