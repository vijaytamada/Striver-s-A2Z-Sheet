/*
    ============================================================
    TOPIC   : Heaps - Basic
    PROBLEM : Convert a Min-Heap array to a Max-Heap array
    ============================================================

    INTUITION:
    ----------
    - A min-heap array is just an array; to turn it into a valid
      max-heap, ignore its previous structure and simply run the
      standard "build heap" procedure (heapify) treating it as max-heap.
    - Heapify from the last non-leaf node up to the root fixes the
      whole array in place, bottom-up.

    STEPS:
    ----------
    1. Start from last non-leaf index: n/2 - 1, go down to index 0.
    2. For each index i, call heapify(i): find the largest among
       node i, left child, right child.
    3. If largest != i, swap and recursively heapify the affected
       subtree.
    4. After processing every non-leaf node, the whole array is a
       valid max-heap.

    VARIATIONS TO REMEMBER:
    ----------
    - This is the exact "Build Heap" step used before Heap Sort
      (O(n) build, then repeated extract-max).
    - Same idea works to convert max-heap -> min-heap by flipping
      the comparison inside heapify.

    TIME COMPLEXITY  : O(n) -> build-heap is linear, not O(n log n)
    SPACE COMPLEXITY : O(log n) -> recursion stack for heapify
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapify(vector<int>& heap, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(heap, largest);
        }
    }

    vector<int> minToMaxHeap(vector<int> nums) {
        vector<int> maxHeap = nums;
        for (int i = maxHeap.size() / 2 - 1; i >= 0; i--) {
            heapify(maxHeap, i);
        }
        return maxHeap;
    }
};

int main() {
    return 0;
}