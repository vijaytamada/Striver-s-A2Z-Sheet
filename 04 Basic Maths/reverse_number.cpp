/*
    ============================================================
    TOPIC   : Basic Maths
    PROBLEM : Reverse a Number
    ============================================================

    INTUITION:
    ----------
    - Peel off digits from the end of n one at a time (n % 10), and build
      the reversed number by shifting the result left and adding each
      peeled digit.

    STEPS:
    ----------
    1. Start reversedNumber at 0.
    2. Extract last digit: lastDigit = n % 10.
    3. Append it: reversedNumber = reversedNumber * 10 + lastDigit.
    4. Remove last digit from n: n = n / 10. Repeat until n becomes 0.

    VARIATIONS TO REMEMBER:
    ----------
    - This exact digit-extraction loop is reused in check_palindrome_number
      (compare reversed to original) and armstrong_number (cube instead of
      append).
    - Watch for integer overflow if reversing very large numbers.

    TIME COMPLEXITY  : O(log10(n)) -> one pass per digit of n
    SPACE COMPLEXITY : O(1) -> only a few extra variables
    ============================================================
*/

// Take a number as input. Extract each digit from the number and build a new number by reversing the digits. Finally, print the reversed number.

// Intuition:
// To reverse the digits of a number, we can repeatedly extract the last digit and append it

// Time Complexity: O(log10(n)), where n is the input number. This is because in each step, we are dividing the number by 10, which reduces the number of digits by one. Therefore, the number of steps required to reverse the number is proportional to the number of digits in the number, which is log10(n).

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int reversedNumber = 0;
    while (n > 0) {
        int lastDigit = n % 10;                            // Extract the last digit
        reversedNumber = reversedNumber * 10 + lastDigit;  // Append it to the reversed number
        n = n / 10;                                        // Remove the last digit from the original number
    }

    cout << "Reversed Number: " << reversedNumber << endl;

    return 0;
}