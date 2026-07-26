/*
    ============================================================
    TOPIC   : Greedy Algos - Easy
    PROBLEM : Fractional Knapsack (maximize value, items can be split)
    ============================================================

    INTUITION:
    ----------
    - Unlike 0/1 knapsack, items can be broken into fractions here, so
      the greedy choice is always optimal: prefer items with the
      highest value/weight ratio first.
    - Fill the knapsack with whole items in that order; when the last
      item doesn't fully fit, take only the fraction of it needed to
      fill remaining capacity.

    STEPS:
    ----------
    1. Sort items descending by value/weight ratio.
    2. Iterate items; if the item fits fully (curWeight + weight <= W),
       take it whole and add its full value.
    3. Otherwise take only the remaining capacity's worth as a
       fraction: (value/weight) * remainingCapacity, then stop.

    VARIATIONS TO REMEMBER:
    ----------
    - "0/1 Knapsack" -> items can't be split, greedy fails there;
      needs DP instead.
    - Same ratio-based greedy idea appears in job sequencing /
      scheduling for max profit problems.

    TIME COMPLEXITY  : O(n log n) -> sorting items by ratio
    SPACE COMPLEXITY : O(1) -> excluding sort's internal space
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Struct to represent an item with value and weight
struct Item {
    int value;
    int weight;
};

class Solution {
public:
    // Comparator function to sort items by value/weight ratio
    bool static comp(Item a, Item b) {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;  // Return true if the ratio of item a is greater than item b
    }

    // Function to calculate the maximum value we can get with fractional knapsack
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Sort items based on the value/weight ratio
        sort(arr, arr + n, comp);

        int curWeight = 0;        // Current weight of knapsack
        double finalvalue = 0.0;  // Final value we can achieve

        // Iterate through the sorted items
        for (int i = 0; i < n; i++) {
            // If the current item can be fully added to the knapsack
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;  // Add the full value of the item
            } else {
                // If the current item can't be fully added, take the fractional part
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;  // Break as we have filled the knapsack
            }
        }

        return finalvalue;  // Return the maximum value that can be carried
    }
};

int main() {
    int n = 3, weight = 50;  // Number of items and capacity of knapsack
    // Item values and weights
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};
    Solution obj;

    // Calculate the maximum value we can get with the fractional knapsack
    double ans = obj.fractionalKnapsack(weight, arr, n);

    // Output the result
    cout << "The maximum value is " << setprecision(2) << fixed << ans;

    return 0;
}

int main() {
    return 0;
}