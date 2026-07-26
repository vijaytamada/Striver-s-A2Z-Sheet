/*
    ============================================================
    TOPIC   : Greedy Algos - Easy
    PROBLEM : Lemonade Change (can every customer be given correct change?)
    ============================================================

    INTUITION:
    ----------
    - Only 3 bill types matter: $5, $10, $20. Track how many $5 and
      $10 bills we're holding (a $20 is never useful as change).
    - For a $10 bill, customer needs one $5 back.
    - For a $20 bill, greedily prefer giving one $10 + one $5 (saves
      $5 bills, which are more "flexible" / harder to make change with)
      over three $5s; only fall back to three $5s if no $10 available.

    STEPS:
    ----------
    1. Maintain counts of $5 and $10 bills held (wallet).
    2. Bill == 5: just add to wallet, no change needed.
    3. Bill == 10: need one $5 as change; fail if none available.
    4. Bill == 20: prefer using one $10 + one $5; else use three $5s;
       else fail (can't make change).

    VARIATIONS TO REMEMBER:
    ----------
    - Greedy is correct here specifically because giving $10 change
      (over three $5s) for a $20 never hurts future flexibility, and
      is provably at least as good.

    TIME COMPLEXITY  : O(n) -> single pass over bills
    SPACE COMPLEXITY : O(1) -> fixed-size wallet array
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> wallet(3, 0);

        for (int bill : bills) {
            if (bill == 5) {
                wallet[0]++;
            }
            else if (bill == 10) {
                if (wallet[0] == 0) return false;
                wallet[0]--;
                wallet[1]++;
            }
            else { 
                if (wallet[1] > 0 && wallet[0] > 0) {
                    wallet[1]--;
                    wallet[0]--;
                }
                else if (wallet[0] >= 3) {
                    wallet[0] -= 3;
                }
                else {
                    return false;
                }
                wallet[2]++;
            }
        }
        
        return true;
    }
};


int main()
{
    

    return 0;
}