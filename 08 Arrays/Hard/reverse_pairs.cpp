/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : Reverse Pairs (count pairs i < j where arr[i] > 2 * arr[j])
    ============================================================

    INTUITION:
    ----------
    - Brute force: check every pair with two nested loops, O(n^2). Use
      long long / 2LL to avoid overflow when comparing.
    - Optimal: same merge-sort-based counting trick as count_inversion.cpp,
      but the condition (arr[i] > 2*arr[j]) is NOT monotonic in the same
      simple way during the standard merge, so it needs its OWN counting
      pass with a separate pointer j, done BEFORE the actual merge step
      (because once merging starts, the array gets reordered and indices
      no longer mean the same thing).

    STEPS (Optimal):
    ----------
    1. Recursively mergeSort left half and right half, summing reverse
       pair counts from each.
    2. Before merging: for each i in the left half, advance a pointer j
       in the right half while arr[i] > 2*arr[j]. The count of valid j's
       for this i is (j - (mid+1)) - add that to the total.
    3. Then do the normal merge step (like standard merge sort) to
       actually sort the combined range.

    VARIATIONS TO REMEMBER:
    ----------
    - Count Inversions (arr[i] > arr[j]) -> simpler version, counting can
      happen DURING the merge itself, see count_inversion.cpp.
    - "Count of smaller numbers after self" -> similar merge-sort counting.

    TIME COMPLEXITY  : O(n log n) -> merge sort recurrence with an extra O(n) counting pass per merge (brute force is O(n^2))
    SPACE COMPLEXITY : O(n) -> temp array used during merge
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution1 {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((long long)nums[i] > 2LL * nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

// Optimal Approach using Modified Merge Sort
class Solution2 {
public:
    int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int rev_pair = 0;

        // Count reverse pairs before merging
        int j = mid + 1;
        for (int i = left; i <= mid; ++i) {
            while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
                ++j;
            }
            rev_pair += (j - (mid + 1));
        }

        // Standard merge step
        int i = left;
        j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid)
            temp[k++] = arr[i++];
        while (j <= right)
            temp[k++] = arr[j++];

        for (int idx = left; idx <= right; ++idx) {
            arr[idx] = temp[idx];
        }

        return rev_pair;
    }

    int mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
        int rev_pair = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            rev_pair += mergeSort(arr, temp, left, mid);
            rev_pair += mergeSort(arr, temp, mid + 1, right);
            rev_pair += merge(arr, temp, left, mid, right);
        }
        return rev_pair;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        return mergeSort(nums, temp, 0, n - 1);
    }
};

int main() {
    return 0;
}