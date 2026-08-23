#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
  public:
    int helper(int idx, vector<int> &arr){
        if(idx == 0){
            return arr[0];
        }

        // pick element
        int pick_sum = arr[idx];
        if(idx - 2 >= 0)
            pick_sum += helper(idx - 2, arr);

        // do not pick element
        int not_pick_sum = helper(idx - 1, arr);

        return max(pick_sum, not_pick_sum);
    }

    int findMaxSum(vector<int>& arr) {
        // code here
        return helper(arr.size() - 1, arr);
    }
};

// Soln 02: Memoization
class Solution2 {
  public:
    int helper(int idx, vector<int> &arr, vector<int>& dp){
        if(idx == 0){
            return arr[0];
        }

        if(dp[idx] != -1)
            return dp[idx];

        // pick element
        int pick_sum = arr[idx];
        if(idx - 2 >= 0)
            pick_sum += helper(idx - 2, arr, dp);

        // do not pick element
        int not_pick_sum = helper(idx - 1, arr, dp);

        return dp[idx] = max(pick_sum, not_pick_sum);
    }

    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int> dp(arr.size(), -1);
        return helper(arr.size() - 1, arr, dp);
    }
};

// Soln 03: Tabulation
class Solution3 {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int> dp(arr.size(), -1);
        
        dp[0] = arr[0];
        
        
        for(int i=1; i<arr.size(); i++){
            // pick element
            int pick_sum = arr[i];
            if(i - 2 >= 0)
                pick_sum += dp[i - 2];

            // do not pick element
            int not_pick_sum = dp[i - 1];
            dp[i] = max(pick_sum, not_pick_sum);
        }
        
        return dp.back();
    }
};

// Soln 04: Space Optimization
class Solution4 {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int prev = arr[0];
        int prev2 = 0;
        
        for(int i=1; i<arr.size(); i++){
            // pick element
            int pick_sum = arr[i];
            if(i - 2 >= 0)
                pick_sum += prev2;

            // do not pick element
            int not_pick_sum = prev;
            int curr = max(pick_sum, not_pick_sum);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};

int main()
{
    

    return 0;
}