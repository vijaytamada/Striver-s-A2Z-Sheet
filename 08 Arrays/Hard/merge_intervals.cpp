/*
    ============================================================
    TOPIC   : Arrays - Hard
    PROBLEM : Merge Intervals
    ============================================================

    INTUITION:
    ----------
    - Sort intervals by start time first - this guarantees any intervals
      that can merge will be next to each other.
    - Walk through and keep a "current merged interval" (start, end).
      If the next interval's start is <= current end, they overlap, so
      extend end to the max of both. Otherwise, the current interval is
      finalized - push it and start a new one.

    STEPS:
    ----------
    1. Sort intervals by start value.
    2. Initialize start/end from the first interval.
    3. For each subsequent interval: if its start <= current end, merge
       (end = max(end, its end)). Otherwise, push {start, end} to answer
       and reset start/end to this interval.
    4. Push the final {start, end} after the loop.

    VARIATIONS TO REMEMBER:
    ----------
    - "Insert Interval" -> similar merging logic but inserting one new
      interval into an already-sorted, non-overlapping list.
    - "Meeting Rooms" problems use the same sort-by-start-time idea.

    TIME COMPLEXITY  : O(n log n) -> dominated by the sort
    SPACE COMPLEXITY : O(n) -> output array (or O(log n) extra for sort)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> ans;

        for (int i = 1; i < intervals.size(); i++) {
            int nextStart = intervals[i][0];
            int nextEnd = intervals[i][1];

            if (end >= nextStart) {
                end = max(end, nextEnd);
            } else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});
        return ans;
    }
};

int main() {
    return 0;
}