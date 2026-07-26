/*
    ============================================================
    TOPIC   : Greedy Algos - Easy
    PROBLEM : Assign Cookies (satisfy max children with min cookie sizes)
    ============================================================

    INTUITION:
    ----------
    - Greedy: to satisfy as many children as possible, always try to
      satisfy the least-greedy child with the smallest cookie that
      is big enough for them.
    - Sort both greed factors and cookie sizes ascending, then two-
      pointer walk through both.

    STEPS:
    ----------
    1. Sort greed array g[] and cookie sizes s[] ascending.
    2. Use pointers i (children) and j (cookies).
    3. If s[j] >= g[i], this cookie satisfies child i -> count it, i++.
    4. Always move j++ (whether or not it satisfied a child) — a used
       or too-small cookie is not reusable.
    5. Continue until either pointer runs out.

    VARIATIONS TO REMEMBER:
    ----------
    - Classic greedy matching pattern: sort both sides, two-pointer
      match smallest-fits-smallest first.
    - Similar in spirit to interval scheduling / activity selection.

    TIME COMPLEXITY  : O(n log n + m log m) -> sorting both arrays
    SPACE COMPLEXITY : O(1) -> excluding sort's internal space
    ============================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;

        int res = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                res++;
                i++;
            }

            j++;
        }

        return res;
    }
};

int main() {
    return 0;
}