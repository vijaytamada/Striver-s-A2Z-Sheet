/*
    ============================================================
    TOPIC   : Heaps - Medium
    PROBLEM : Merge K Sorted Linked Lists
    ============================================================

    INTUITION:
    ----------
    - Solution1: merge lists two at a time using the classic "merge
      two sorted lists" logic, folding the whole list of lists into one.
      Simple but repeats merging work (O(k) merges, each up to O(n)).
    - Solution2 (better): use a min-heap holding at most one node from
      each list at a time. Always pop the globally smallest node,
      attach it to result, and push its `next` back into the heap.
      This avoids repeated re-comparison of already-merged lists.

    STEPS (Solution2 - optimal):
    ----------
    1. Push the head of every list into a min-heap (ordered by val).
    2. Pop the smallest node, attach it to the result's tail.
    3. If that node has a `next`, push it into the heap.
    4. Repeat until heap is empty.

    VARIATIONS TO REMEMBER:
    ----------
    - "Merge K Sorted Arrays" -> same heap idea, but heap stores
      (value, list index, element index) tuples instead of nodes.
    - Divide and conquer (pairwise merge in log k rounds) is another
      O(N log k) alternative without extra heap space.

    TIME COMPLEXITY  : O(N log k) -> N total nodes, heap operations O(log k)
                        (Solution1 is O(N*k) in the worst case)
    SPACE COMPLEXITY : O(k) -> heap holds at most k nodes at a time
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Using merge two sorted list logic and take consider 2 everytime
class Solution1 {
public:
    // Function to merge two sorted linked lists.
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        current->next = l1 ? l1 : l2;

        return dummy.next;
    }

    // Function to merge k sorted linked lists.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        // Merge arrays one by one.
        ListNode* head = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }

        return head;
    }
};

// Using Min-Heap (Priority Queue)
class Solution2 {
public:
    // Function to merge k sorted linked lists.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        // Push the head of each list into the min-heap.
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            current->next = smallest;
            current = current->next;

            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};

int main() {
    return 0;
}