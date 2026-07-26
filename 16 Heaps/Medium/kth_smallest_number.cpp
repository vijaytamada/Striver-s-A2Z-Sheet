/*
    ============================================================
    TOPIC   : Heaps - Medium
    PROBLEM : Kth Smallest Element in an Array
    ============================================================

    INTUITION:
    ----------
    - Solution1: sort ascending and pick index k-1. Simple but
      O(n log n), sorts more than necessary.
    - Solution2: keep a MAX-heap of size k. Push every element; if
      heap grows beyond size k, pop the largest. At the end, the
      heap's top is the kth smallest (the largest among the k smallest).

    STEPS (Solution2 - optimal):
    ----------
    1. Maintain a max-heap (default priority_queue<int>).
    2. For each num, push it into the heap.
    3. If heap size > k, pop the top (largest element) — discards
       elements that can't be in the "bottom k smallest" group.
    4. After processing all elements, heap.top() = kth smallest.

    VARIATIONS TO REMEMBER:
    ----------
    - "Kth Largest Element" -> mirror: use a MIN-heap of size k instead.
    - Quickselect solves this in average O(n) as an alternative.

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
    int findKthSmallest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[k - 1];
    }
};

// Solution using Min-Heap
class Solution2 {
public:
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for (int num : nums) {
            maxHeap.push(num);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        return maxHeap.top();
    }
};

int main() {
    return 0;
}