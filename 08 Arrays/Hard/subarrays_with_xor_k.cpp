/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : Count Subarrays with XOR equal to K
    ============================================================

    INTUITION:
    ----------
    - Same prefix-technique idea as "subarray sum equals k", but using
      XOR instead of addition.
    - Key property: if prefixXor(0..j) ^ prefixXor(0..i-1) = k, then the
      XOR of the subarray (i..j) equals k. Rearranging: prefixXor(0..i-1)
      = currXor ^ k. So for each position, check how many times
      (currXor ^ k) has appeared before as a prefix XOR.
    - XOR is its own inverse (a^a=0), which is what makes this rearrangement
      work, similar to how subtraction works for sums.

    STEPS:
    ----------
    1. currXor = 0, res = 0, empty hashmap (xorMap).
    2. For each number: currXor ^= number.
    3. If currXor == k itself, count this subarray (from start to here).
    4. If (currXor ^ k) exists in xorMap, add its frequency to res (each
       occurrence marks a valid starting point).
    5. Increment xorMap[currXor] to record this prefix XOR occurrence.
    6. Return res.

    VARIATIONS TO REMEMBER:
    ----------
    - Subarray sum equals k -> same pattern with addition/subtraction
      instead of XOR, see subarrays_sum_equals_k.cpp.
    - Longest subarray with XOR k -> store first index only instead of
      frequency count.

    TIME COMPLEXITY  : O(n) -> single pass with hashmap lookups
    SPACE COMPLEXITY : O(n) -> hashmap can store up to n distinct prefix XORs
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        unordered_map<int, int> xorMap;
        int currXor = 0;
        int res = 0;

        for (int num : nums) {
            currXor ^= num;

            // If currXor itself is equal to k, count this subarray
            if (currXor == k) {
                res++;
            }

            // If there exists a prefix XOR such that currXor ^ prefix = k
            // then prefix = currXor ^ k
            if (xorMap.find(currXor ^ k) != xorMap.end()) {
                res += xorMap[currXor ^ k];
            }

            // Store the current XOR in the map
            xorMap[currXor]++;
        }

        return res;
    }
};

int main() {
    return 0;
}