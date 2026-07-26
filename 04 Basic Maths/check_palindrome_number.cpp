/*
    ============================================================
    TOPIC   : Basic Maths
    PROBLEM : Check Palindrome Number
    ============================================================

    INTUITION:
    ----------
    - A number is a palindrome if it reads the same forwards and backwards.
    - Build the reverse of the number digit by digit, then just compare it
      to the original - no need for string conversion.

    STEPS:
    ----------
    1. Save the original number for later comparison.
    2. Extract the last digit (n % 10) and append it to reversedNumber
       (reversedNumber = reversedNumber * 10 + lastDigit).
    3. Remove the last digit (n / 10) and repeat until n becomes 0.
    4. If reversedNumber == originalNumber, it's a palindrome.

    VARIATIONS TO REMEMBER:
    ----------
    - Same digit-reversal trick as reverse_number.cpp - this is just that
      logic plus a comparison.
    - Negative numbers are never palindromes (the '-' sign breaks symmetry) -
      handle as an edge case if asked.

    TIME COMPLEXITY  : O(log10(n)) -> one pass per digit of n
    SPACE COMPLEXITY : O(1) -> only a few extra variables
    ============================================================
*/

// Make a copy of the original number. Extract each digit from the number and build a new number by reversing the digits. After the loop, compare the reversed number with the original number to check whether it is a palindrome or not.

// Time Complexity: O(log10(n)), where n is the input number. This is because in each step, we are dividing the number by 10, which reduces the number of digits by one. Therefore, the number of steps required to reverse the number is proportional to the number of digits in the number, which is log10(n).

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int originalNumber = n;  // Store the original number for comparison
    int reversedNumber = 0;

    while (n > 0) {
        int lastDigit = n % 10;
        reversedNumber = reversedNumber * 10 + lastDigit;
        n = n / 10;
    }

    if (originalNumber == reversedNumber) {
        cout << originalNumber << " is a palindrome number." << endl;
    } else {
        cout << originalNumber << " is not a palindrome number." << endl;
    }

    return 0;
}