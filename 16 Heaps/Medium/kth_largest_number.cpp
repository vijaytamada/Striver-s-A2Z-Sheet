/*
    ============================================================
    TOPIC   : Heaps - Medium
    PROBLEM : Kth Largest Element in an Array
    ============================================================

    INTUITION:
    ----------
    - Solution1: just sort descending and pick index k-1. Simple but
      O(n log n) and sorts the whole array unnecessarily.
    - Solution2: keep a MIN-heap of size k. Push every element; if
      heap grows beyond size k, pop the smallest. At the end, the
      heap's top is the kth largest (the smallest among the k largest).

    STEPS (Solution2 - optimal):
    ----------
    1. Maintain a min-heap (priority_queue with greater<int>).
    2. For each num, push it into the heap.
    3. If heap size > k, pop the top (smallest element) — this
       discards elements that can't be in the "top k largest" group.
    4. After processing all elements, heap.top() = kth largest.

    VARIATIONS TO REMEMBER:
    ----------
    - "Kth Smallest Element" -> mirror: use a MAX-heap of size k instead.
    - Quickselect (Hoare partition) solves this in average O(n) if
      heap's O(n log k) isn't good enough.

    TIME COMPLEXITY  : O(n log k) -> n pushes/pops on heap of size k
    SPACE COMPLEXITY : O(k) -> heap holds at most k elements
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

// Medium - Kth Largest Element in an Array
// Solution using sorting
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

// Solution using Min-Heap
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

int main() {
    return 0;
}