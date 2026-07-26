/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Majority Element (appears more than n/2 times)
    ============================================================

    INTUITION:
    ----------
    - Brute force: count frequency of every number using a hashmap,
      O(n) time but O(n) space.
    - Optimal (Boyer-Moore Voting Algorithm): think of it like a fight -
      pick a candidate and a count. If we see the same element, count++;
      if we see a different one, count--. When count hits 0, switch
      candidate to the current element. Because the majority element
      appears more than n/2 times, it always "wins" and survives as the
      final candidate.

    STEPS (Boyer-Moore):
    ----------
    1. ele = 0, count = 0.
    2. For each number: if count == 0, set ele = number, count = 1.
    3. Else if number == ele, count++.
    4. Else count--.
    5. Return ele (guaranteed to be the majority element since it's
       assumed one exists).

    VARIATIONS TO REMEMBER:
    ----------
    - No guarantee a majority exists -> need a verification pass counting
      occurrences of the candidate.
    - Majority element appearing more than n/3 times -> need to track TWO
      candidates, see majority_element_2.cpp.

    TIME COMPLEXITY  : O(n) -> single pass (hashmap version also O(n) but with extra space)
    SPACE COMPLEXITY : O(1) for Boyer-Moore; O(n) for the hashmap version
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Majority Element

// Soln 1 - Using Hashmap
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap;

        for (int num : nums) {
            countMap[num]++;
            if (countMap[num] > nums.size() / 2) {
                return num;
            }
        }

        return -1;
    }
};

// Soln 2 - Boyer moore's voting algo
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0;
        int count = 0;

        for (int& it : nums) {
            if (count == 0) {
                ele = it;
                count = 1;
            } else if (ele == it) {
                count++;
            } else {
                count--;
            }
        }

        return ele;
    }
};

int main() {
    return 0;
}