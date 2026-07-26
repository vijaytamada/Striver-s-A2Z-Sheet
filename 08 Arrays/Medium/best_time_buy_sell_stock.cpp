/*
    ============================================================
    TOPIC   : Arrays - Medium
    PROBLEM : Best Time to Buy and Sell Stock (single transaction)
    ============================================================

    INTUITION:
    ----------
    - To maximize profit from one buy + one sell, at every price we ask
      "what's the best profit if I sell today?" which is today's price
      minus the minimum price seen so far (the best day to have bought).
    - Track the running minimum price and the running max profit together
      in a single pass.

    STEPS:
    ----------
    1. currMin = prices[0], maxProfit = 0.
    2. For each price: currMin = min(currMin, price).
    3. maxProfit = max(maxProfit, price - currMin).
    4. Return maxProfit.

    VARIATIONS TO REMEMBER:
    ----------
    - Buy/sell multiple times (unlimited transactions) -> sum up every
      positive difference between consecutive days.
    - Buy/sell with cooldown or transaction fee -> needs DP with states.
    - At most K transactions -> DP on (day, transactions used, holding stock).

    TIME COMPLEXITY  : O(n) -> single pass over prices
    SPACE COMPLEXITY : O(1) -> only two variables tracked
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = prices[0];
        int maxProfit = 0;

        for (int& it : prices) {
            currMin = min(currMin, it);
            maxProfit = max(maxProfit, it - currMin);
        }

        return maxProfit;
    }
};

int main() {
    return 0;
}