/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Sort Colors (Dutch National Flag - sort array of only 0s,1s,2s)
    ============================================================

    INTUITION:
    ----------
    - Simplest: just call sort() - O(n log n), doesn't use the fact that
      there are only 3 distinct values.
    - Counting sort: count occurrences of 0, 1, 2, then overwrite the
      array in order - O(n) but needs two passes.
    - Optimal (Dutch National Flag / one-pass three-way partition): use
      three pointers - low, mid, high. Everything before low is 0,
      everything after high is 2, and mid scans the unknown middle region.
      Swap and move pointers based on what mid currently points to.

    STEPS (Dutch National Flag):
    ----------
    1. low = 0, mid = 0, high = n-1.
    2. While mid <= high:
       - if nums[mid] == 0: swap(nums[low], nums[mid]), low++, mid++.
       - if nums[mid] == 1: mid++ (already in the right zone).
       - if nums[mid] == 2: swap(nums[mid], nums[high]), high-- (don't
         increment mid here - the swapped-in value needs to be checked).

    VARIATIONS TO REMEMBER:
    ----------
    - This 3-way partitioning pattern generalizes to quicksort's
      "3-way partition" for arrays with many duplicate keys.

    TIME COMPLEXITY  : O(n) -> single pass for DNF algorithm
    SPACE COMPLEXITY : O(1) -> in-place swaps only
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Sort Colors (Dutch National Flag Problem)

// Soln 1 - Using inbuilt sort function
class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

// Soln 2 - Using Counting Sort
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0, 0, 0};

        for (int num : nums) {
            count[num]++;
        }

        int index = 0;
        for (int i = 0; i < 3; i++) {
            while (count[i]--) {
                nums[index++] = i;
            }
        }
    }
};

// Soln 3 - Using Dutch National Flag Algorithm
class Solution3 {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    return 0;
}