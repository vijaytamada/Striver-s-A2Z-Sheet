/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Leaders in an Array
    ============================================================

    INTUITION:
    ----------
    - An element is a "leader" if it's strictly greater than everything
      to its right.
    - Instead of checking every element against everything on its right
      (O(n^2)), scan from the RIGHT and keep track of the max seen so far.
      Any element bigger than that running max is automatically a leader
      (since everything to its right is <= that max).

    STEPS:
    ----------
    1. currMax = INT_MIN.
    2. Loop i from n-1 down to 0: if nums[i] > currMax, it's a leader -
       push it and update currMax = nums[i].
    3. Since we collected leaders back-to-front, reverse the result at
       the end to restore original left-to-right order.

    VARIATIONS TO REMEMBER:
    ----------
    - Rightmost element is always a leader (nothing to its right).
    - Similar right-to-left scanning trick used in "trapping rain water"
      and "next greater element" problems.

    TIME COMPLEXITY  : O(n) -> single right-to-left pass
    SPACE COMPLEXITY : O(1) extra (excluding the output array)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> res;
        int currMax = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > currMax) {  // strictly greater
                res.push_back(nums[i]);
                currMax = nums[i];
            }
        }

        reverse(res.begin(), res.end());  // maintain original order
        return res;
    }
};

int main() {
    return 0;
}