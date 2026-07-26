/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : Merge Two Sorted Arrays In-Place (nums1 has extra trailing space)
    ============================================================

    INTUITION:
    ----------
    - Easy way: merge into a separate result array using two pointers,
      then copy back - uses O(m+n) extra space.
    - Optimal (no extra space): nums1 has size m+n, with the last n slots
      empty/unused, meant to hold the final merged result.
      Fill nums1 from the BACK using three pointers: one at the end of the
      real nums1 data (index m-1), one at the end of nums2 (index n-1),
      and one at the very end of nums1's full length (index m+n-1).
      Always place the LARGER of the two candidates at the back and move
      that pointer down - this way we never overwrite data we still need.

    STEPS (No extra space):
    ----------
    1. First shift nums1's real m elements to the tail portion of nums1
       (so positions 0..n-1 are free) - this specific implementation does
       this shift first, then merges nums2 in from the front using a
       forward pass with pointers i (into shifted nums1) and j (into nums2).
    2. Compare nums1[i] and nums2[j], place smaller at nums1[idx], advance
       that pointer and idx.
    3. Copy any remaining elements from either side once one runs out.

    VARIATIONS TO REMEMBER:
    ----------
    - The "fill from the back, always place larger" variant is the more
      commonly taught O(1) space version - functionally equivalent, just
      merges from the opposite end.

    TIME COMPLEXITY  : O(m + n) -> each element processed a constant number of times
    SPACE COMPLEXITY : O(1) for in-place version; O(m + n) for the extra-array version
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Soln using extra space
class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m + n, 0);

        int i = 0;
        int j = 0;
        int idx = 0;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                res[idx] = nums1[i];
                i++;
            } else {
                res[idx] = nums2[j];
                j++;
            }
            idx++;
        }

        while (i < m) {
            res[idx++] = nums1[i];
            i++;
        }

        while (j < n) {
            res[idx++] = nums2[j];
            j++;
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = res[i];
        }
    }
};

// Soln without using extra space
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;
        for (int i = m - 1; i >= 0; i--) {
            nums1[idx--] = nums1[i];
        }

        int i = n;
        int j = 0;
        idx = 0;

        while (i < m + n && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums1[idx] = nums1[i];
                i++;
            } else {
                nums1[idx] = nums2[j];
                j++;
            }
            idx++;
        }

        while (i < m + n) {
            nums1[idx++] = nums1[i];
            i++;
        }

        while (j < n) {
            nums1[idx++] = nums2[j];
            j++;
        }
    }
};

int main() {
    return 0;
}