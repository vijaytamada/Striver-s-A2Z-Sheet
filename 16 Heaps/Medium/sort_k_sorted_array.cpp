/*
    ============================================================
    TOPIC   : Heaps - Medium
    PROBLEM : Sort a Nearly/K-Sorted Array
              (each element is at most k positions from its sorted spot)
    ============================================================

    INTUITION:
    ----------
    - Since every element is at most k away from its correct sorted
      position, at any time the correct "next smallest" element must
      already be among the next k+1 elements seen so far.
    - Keep a min-heap of size k+1. The heap's top is always the next
      element to place in sorted order.

    STEPS:
    ----------
    1. Push the first k+1 elements into a min-heap.
    2. For each remaining element: pop the heap's top into the result
       (next sorted position), then push the new element in.
    3. Once all elements are read, pop the rest of the heap into result.

    VARIATIONS TO REMEMBER:
    ----------
    - This is a streaming-friendly sort — useful when data arrives
      as a stream and you can't wait for it all before sorting.
    - Similar heap-window idea as "Kth Largest/Smallest" but here the
      window slides through the whole array instead of shrinking to k.

    TIME COMPLEXITY  : O(n log k) -> n heap push/pop ops on size-k heap
    SPACE COMPLEXITY : O(k) -> heap holds at most k+1 elements
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortKsortedArray(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = nums.size();
        int i = 0;

        // Step 1: Push first k+1 elements
        while (i <= k) {
            minHeap.push(nums[i]);
            i++;
        }

        int pos = 0;

        // Step 2: Process remaining elements
        for (; i < n; i++) {
            nums[pos++] = minHeap.top();
            minHeap.pop();
            minHeap.push(nums[i]);
        }

        // Step 3: Empty the heap
        while (!minHeap.empty()) {
            nums[pos++] = minHeap.top();
            minHeap.pop();
        }

        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    vector<int> sorted = sol.sortKsortedArray(nums, k);

    for (int x : sorted)
        cout << x << " ";
    return 0;
}