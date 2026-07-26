/*
    ============================================================
    TOPIC   : Basic Maths
    PROBLEM : Print All Divisors of a Number
    ============================================================

    INTUITION:
    ----------
    - Divisors always come in pairs (i, n/i). Once i exceeds sqrt(n), the
      pairs start repeating in reverse, so we only need to loop up to
      sqrt(n) and collect both members of each pair.

    STEPS:
    ----------
    1. Loop i from 1 while i*i <= n.
    2. If i divides n, add i to the list; also add n/i if it's different
       from i (avoids duplicating the square root itself).
    3. Sort the collected divisors before printing (they come out
       unordered since both small and large divisors are mixed in).

    VARIATIONS TO REMEMBER:
    ----------
    - Naive approach: loop i from 1 to n and check n % i == 0 - O(n),
      much slower than the sqrt(n) approach here.
    - Counting divisors (not listing them) can skip the sort/collect step
      and just increment a counter.

    TIME COMPLEXITY  : O(sqrt(n) log(sqrt(n))) -> sqrt(n) loop + sorting up to sqrt(n) divisors
    SPACE COMPLEXITY : O(sqrt(n)) -> for storing the divisors list
    ============================================================
*/

// Find all divisors of a given number using an efficient approach. Loop from 1 to the square root of the number and check if the current value divides the number. If it does, add both the divisor and its paired value (n / i) to the list. After collecting all divisors, sort the list and print them in ascending order.

// Intuition:
// Divisors always come in pairs. If i divides n, then n / i is also a divisor. One of these will be smaller than or equal to √n, and the other will be greater. So, by checking only up to √n, we can find all divisors efficiently and avoid unnecessary iterations.

// Time Complexity: O(√n log(√n)) in the worst case, where n is the input number. This is because we are iterating up to the square root of n to find divisors, and then sorting the list of divisors, which can have at most O(√n) elements.

#include <algorithm>  // for sort
#include <iostream>
#include <vector>
using namespace std;

vector<int> getDivisors(int n) {
    vector<int> divisors;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());  // ensure sorted order
    return divisors;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    vector<int> divisors = getDivisors(num);
    cout << "Divisors of " << num << " in sorted order:\n";
    for (int d : divisors) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}