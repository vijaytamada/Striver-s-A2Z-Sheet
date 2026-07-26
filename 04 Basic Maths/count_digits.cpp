/*
    ============================================================
    TOPIC   : Basic Maths
    PROBLEM : Count Digits in a Number
    ============================================================

    INTUITION:
    ----------
    - Every time you divide a number by 10, you chop off one digit. So
      counting how many divisions it takes to reach 0 gives the digit count.

    STEPS:
    ----------
    1. Start a counter at 0.
    2. While n != 0: divide n by 10 (integer division), increment counter.
    3. Counter holds the final digit count.

    VARIATIONS TO REMEMBER:
    ----------
    - Alternative one-liner: floor(log10(n)) + 1 (careful with n == 0).
    - This same "peel off a digit" loop is the building block for
      reverse_number, palindrome check, and armstrong number.

    TIME COMPLEXITY  : O(log10(n)) -> one division per digit
    SPACE COMPLEXITY : O(1) -> only a counter variable
    ============================================================
*/

// Take a number as input. Repeatedly divide the number by 10 to remove the last digit, and increase a counter each time. Continue this process until the number becomes 0. The counter gives the total number of digits in the number.


// Time Complexity: O(log10(n)), where n is the input number. This is because in each step, we are dividing the number by 10, which reduces the number of digits by one. Therefore, the number of steps required to reduce the number to 0 is proportional to the number of digits in the number, which is log10(n).
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int count = 0;
    while (n != 0) {
        n = n / 10;  // Remove the last digit
        count++;
    }

    cout << "Number of digits: " << count << endl;

    return 0;
}