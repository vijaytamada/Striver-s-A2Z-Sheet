/*
    ============================================================
    TOPIC   : Greedy Algos - Easy
    PROBLEM : Minimum Number of Coins for a Given Value
    ============================================================

    INTUITION:
    ----------
    - With standard denominations (1, 2, 5, 10, 20, 50, 100, 500, 1000),
      always using the largest coin that fits gives the minimum count.
    - This greedy approach works because this particular coin system
      is "canonical" (each denomination divides nicely into the next) —
      it does NOT work for arbitrary coin systems in general.

    STEPS:
    ----------
    1. Iterate denominations from largest to smallest.
    2. For each denomination, use it as many times as possible
       (while V >= coins[i]): subtract from V, record the coin.
    3. Continue until V becomes 0.

    VARIATIONS TO REMEMBER:
    ----------
    - "Coin Change" (LeetCode, min coins for ARBITRARY denominations)
      -> greedy fails here in general, needs DP.
    - This greedy only works because of the specific denomination set
      used (currency-like systems).

    TIME COMPLEXITY  : O(n + V/smallest_coin) -> n = number of
                        denominations, loop until V exhausted
    SPACE COMPLEXITY : O(V) worst case -> for the list of coins used
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Function to compute minimum coins required for value V
vector<int> minCoins(int V) {
    // Available coin denominations
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;

    // Vector to store the result
    vector<int> ans;

    // Iterate from largest to smallest denomination
    for (int i = n - 1; i >= 0; i--) {
        // Use as many coins[i] as possible
        while (V >= coins[i]) {
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }

    // Return the list of coins used
    return ans;
}

int main() {
    // Total amount
    int V = 49;

    // Call function to get coin list
    vector<int> ans = minCoins(V);

    // Print result
    cout << "The minimum number of coins is " << ans.size() << endl;
    cout << "The coins are " << endl;
    for (int coin : ans) {
        cout << coin << " ";
    }
    cout << endl;

    return 0;
}