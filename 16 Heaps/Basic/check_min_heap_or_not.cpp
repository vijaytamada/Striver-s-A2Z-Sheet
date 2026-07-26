/*
    ============================================================
    TOPIC   : Heaps - Basic
    PROBLEM : Check if an array represents a Min-Heap
    ============================================================

    INTUITION:
    ----------
    - A binary heap stored as an array satisfies: for every index i,
      parent (i) <= its children (2i+1, 2i+2) for a min-heap.
    - Just verify this parent-child rule holds for every node.

    STEPS:
    ----------
    1. For each index i, compute left = 2*i+1, right = 2*i+2.
    2. If left child exists and nums[i] > nums[left] -> not a heap.
    3. If right child exists and nums[i] > nums[right] -> not a heap.
    4. If no violation found across all indices, it is a valid min-heap.

    VARIATIONS TO REMEMBER:
    ----------
    - For max-heap check, just flip the comparison (nums[i] < child).
    - Building a heap from array uses this same parent/child index
      math (2i+1, 2i+2, (i-1)/2).

    TIME COMPLEXITY  : O(n) -> single pass over the array
    SPACE COMPLEXITY : O(1) -> no extra space used
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHeap(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < nums.size() && nums[i] > nums[left])
                return false;
            if (right < nums.size() && nums[i] > nums[right])
                return false;
        }

        return true;
    }
};

int main() {
    return 0;
}