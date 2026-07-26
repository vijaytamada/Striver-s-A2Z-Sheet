/*
    ============================================================
    TOPIC   : Basic Hashing
    PROBLEM : Find the Most Frequently Occurring Element
    ============================================================

    INTUITION:
    ----------
    - First build a frequency map of every element (same idea as
      count_freq.cpp). Then scan the map once to find the entry with the
      highest count, breaking ties by picking the smaller value.

    STEPS:
    ----------
    1. Build a frequency map: freq[num]++ for every element in nums.
    2. Initialize maxFreq = 0 and result = INT_MAX (sentinel for "no
       answer yet").
    3. Scan the map: update maxFreq/result whenever a higher count is
       found, or an equal count with a smaller value (tie-break rule).

    VARIATIONS TO REMEMBER:
    ----------
    - If tie-breaking isn't required, just track the first max found.
    - "Majority element" (count > n/2) is a related but distinct problem -
      can be solved in O(1) space with Moore's Voting Algorithm instead of
      hashing.

    TIME COMPLEXITY  : O(n) -> one pass to build the map, one pass to scan it
    SPACE COMPLEXITY : O(n) -> up to n distinct keys stored in the map
    ============================================================
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int mostFrequentElement(const vector<int>& nums) {
    unordered_map<int, int> freq;

    // Count frequencies
    for (int num : nums) {
        freq[num]++;
    }

    int maxFreq = 0;
    int result = INT_MAX;

    // Find element with highest frequency (smallest if tie)
    for (const auto& [num, count] : freq) {
        if (count > maxFreq || (count == maxFreq && num < result)) {
            maxFreq = count;
            result = num;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {10, 20, 10, 30, 20, 10, 30, 30, 30};

    int answer = mostFrequentElement(nums);
    cout << "Most frequent element: " << answer << endl;

    return 0;
}