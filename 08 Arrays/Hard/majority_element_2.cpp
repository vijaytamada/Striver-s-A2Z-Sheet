/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : Majority Element II (elements appearing more than n/3 times)
    ============================================================

    INTUITION:
    ----------
    - HashMap approach: count frequency of every element, then pick out
      any whose count exceeds n/3. Simple but uses O(n) space.
    - Optimal (Extended Boyer-Moore Voting): since more than n/3 means
      AT MOST 2 such elements can exist (three elements each appearing
      more than n/3 times would exceed n total), track TWO candidates and
      TWO counters simultaneously, similar to the n/2 voting trick but
      doubled up.
    - After finding the two candidates, do a second pass to verify their
      actual counts exceed n/3 (voting alone doesn't guarantee validity).

    STEPS (Extended Boyer-Moore):
    ----------
    1. num1 = num2 = 0, count1 = count2 = 0.
    2. For each element: if it matches num1, count1++; else if matches
       num2, count2++; else if count1==0, set num1=element, count1=1;
       else if count2==0, set num2=element, count2=1; else decrement
       both counts (this element "cancels out" one vote from each).
    3. Second pass: recount actual occurrences of num1 and num2.
    4. Only include a candidate in the answer if its actual count > n/3.

    VARIATIONS TO REMEMBER:
    ----------
    - Majority element (n/2 case) -> only needs ONE candidate, see
      majority_element.cpp.
    - Pattern generalizes to "elements appearing more than n/k times"
      using k-1 candidates and counters.

    TIME COMPLEXITY  : O(n) -> two linear passes (voting + verification)
    SPACE COMPLEXITY : O(1) for voting approach; O(n) for the hashmap version
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Solution using HashMap
class Solution1 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int& it : nums) {
            count[it]++;
        }

        vector<int> res;

        for (auto& [key, val] : count) {
            if (val > nums.size() / 3) {
                res.push_back(key);
            }
        }

        return res;
    }
};

// Solution using Boyer-Moore Voting Algorithm
class Solution2 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0, num2 = 0;
        int count1 = 0, count2 = 0;
        
        for(auto it : nums)
        {
            if(it == num1)
                count1++;
            else if(it == num2)
                count2++;
            else if(count1 == 0)
            {
                num1 = it;
                count1 = 1;
            }
            else if(count2 == 0)
            {
                num2 = it;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        vector<int> ans;
        count1 = count2 = 0;
        
        for(auto it : nums)
        {
            if(it == num1)
                count1++;
            
            if(it == num2)
                count2++;
        }
        
        if(count1 > nums.size()/3)
            ans.push_back(num1);
        
        if(count2 > nums.size()/3 && num1 != num2)
            ans.push_back(num2);
        
        return ans;
    }
};

int main()
{
    

    return 0;
}