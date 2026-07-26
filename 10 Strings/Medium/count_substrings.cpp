/*
    ============================================================
    TOPIC   : Strings - Medium
    PROBLEM : Count Substrings with Exactly K Distinct Characters
    ============================================================

    INTUITION:
    ----------
    - "Exactly K" is hard to slide a window on directly, but "At Most K" is
      easy with a standard sliding window (shrink whenever distinct count
      exceeds K).
    - Classic trick: exactly(K) = atMost(K) - atMost(K-1), since atMost(K-1)
      subtracts out everything counted for K-1 or fewer distinct chars.

    STEPS:
    ----------
    1. atMostKDistinct(s, k): two-pointer window [left, right]; expand right,
       add char to frequency map, and while map size exceeds k, shrink from
       left (decrement/erase). For each right, add (right-left+1) to result
       (every substring ending at right within the current valid window).
    2. countSubstrings(s, k) = atMostKDistinct(s, k) - atMostKDistinct(s, k-1).

    VARIATIONS TO REMEMBER:
    ----------
    - "Longest substring with at most K distinct characters" uses the same
      atMostKDistinct window but tracks max length instead of counting.
    - "Longest substring without repeating characters" is the k=all-unique
      special case.

    TIME COMPLEXITY  : O(n) -> each pointer moves forward at most n times, done twice
    SPACE COMPLEXITY : O(k) -> frequency map holds at most k distinct chars
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Function to count substrings with at most k distinct characters
int atMostKDistinct(string s, int k) {
    // Left pointer and result
    int left = 0, res = 0;
    // Frequency map
    unordered_map<char, int> freq;

    // Iterate through string with right pointer
    for (int right = 0; right < s.size(); right++) {
        // Add current character
        freq[s[right]]++;

        // Shrink window if distinct characters exceed k
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        // Count substrings in current window
        res += (right - left + 1);
    }
    return res;
}

// Function to count substrings with exactly k distinct characters
int countSubstrings(string s, int k) {
    // Exactly k = atMost(k) - atMost(k-1)
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    // Sample test
    string s = "pqpqs";
    int k = 2;

    // Output the result
    cout << "Count: " << countSubstrings(s, k) << endl;  // Output: 7
    return 0;
}