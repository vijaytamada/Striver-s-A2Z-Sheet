/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : Utility Algorithms (min/max_element, count, reverse, rotate,
              unique, accumulate, gcd)
    ============================================================

    WHAT & WHY:
    ----------
    - <algorithm> and <numeric> bundle common array operations so you
      don't hand-write loops for things like sum, reverse, or dedup.
    - Knowing these saves time and reduces bugs in interviews/contests.

    KEY POINTS:
    ----------
    1. min_element/max_element -> O(n), return an ITERATOR (dereference
       with * to get the value).
    2. count(val) / count_if(predicate) -> O(n) each.
    3. reverse(begin, end) -> O(n), in-place.
    4. rotate(begin, newBegin, end) -> O(n), left-rotates so newBegin
       becomes the first element.
    5. unique(begin, end) -> O(n), removes CONSECUTIVE duplicates only and
       returns a new logical end; must pair with erase() to actually
       shrink the container (erase-remove idiom) - so sort first if you
       want to remove ALL duplicates, not just adjacent ones.
    6. accumulate(begin, end, initVal) -> O(n), sums (or folds) a range.
    7. gcd(a, b) -> built-in C++17 function in <numeric>, O(log(min(a,b))).

    COMMON PITFALLS / GOTCHAS:
    ----------
    - unique() only removes adjacent duplicates - on an unsorted vector it
      won't remove all copies of a value; sort first if that's the goal.
    - unique() doesn't shrink the vector by itself - always follow with
      erase(newEnd, end()).
    ============================================================
*/

#include <iostream>
#include <vector>
#include <algorithm> // for min_element, max_element, count, count_if, reverse, rotate, unique
#include <numeric>   // for accumulate
using namespace std;

int main() {
    vector<int> nums = {10, 20, 30, 20, 40, 50, 20};

    // --- Min/Max & Counting ---
    auto minIt = min_element(nums.begin(), nums.end());
    auto maxIt = max_element(nums.begin(), nums.end());
    int count20 = count(nums.begin(), nums.end(), 20);
    int evenCount = count_if(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });

    cout << "Min element: " << *minIt << endl;
    cout << "Max element: " << *maxIt << endl;
    cout << "Count of 20: " << count20 << endl;
    cout << "Count of even numbers: " << evenCount << endl;

    // --- Modify / Iterate ---
    swap(nums[0], nums[1]);

    reverse(nums.begin(), nums.end());
    cout << "\nAfter reverse: ";
    for (int x : nums) cout << x << " ";

    rotate(nums.begin(), nums.begin() + 2, nums.end());
    cout << "\nAfter rotate by 2: ";
    for (int x : nums) cout << x << " ";

    // Remove consecutive duplicates using unique + erase
    vector<int> dupes = {1, 1, 2, 2, 2, 3, 3, 4};
    auto newEnd = unique(dupes.begin(), dupes.end());
    dupes.erase(newEnd, dupes.end());

    cout << "\nAfter erase–remove idiom: ";
    for (int x : dupes) cout << x << " ";

    // --- Accumulate ---
    int total = accumulate(nums.begin(), nums.end(), 0);
    cout << "\nSum using accumulate: " << total << endl;

    // GCD function STL
    int a = 56, b = 98;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;

    return 0;
}