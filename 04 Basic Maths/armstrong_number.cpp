/*
    ============================================================
    TOPIC   : Basic Maths
    PROBLEM : Armstrong Number Check
    ============================================================

    INTUITION:
    ----------
    - An Armstrong number equals the sum of the cubes of its own digits
      (for 3-digit numbers). Extract digits one by one, cube each, and
      accumulate the sum.
    - Compare the accumulated sum with the original number at the end.

    STEPS:
    ----------
    1. Save the original number for later comparison.
    2. Repeatedly extract the last digit (n % 10), cube it, add to sum.
    3. Remove the last digit (n / 10) and repeat until n becomes 0.
    4. If sum == originalNumber, it's an Armstrong number.

    VARIATIONS TO REMEMBER:
    ----------
    - For numbers with a different digit count, the power used is the
      digit count (not always 3) - e.g. 4-digit Armstrong numbers cube... no,
      raise digits to the 4th power.
    - Similar digit-extraction pattern is reused in reverse_number and
      check_palindrome_number.

    TIME COMPLEXITY  : O(log10(n)) -> one pass per digit of n
    SPACE COMPLEXITY : O(1) -> only a few extra variables
    ============================================================
*/

// Make a copy of the original number. Extract each digit, cube it, and add it to a total sum. Then, check whether this sum is equal to the original number or not.

// Time Complexity: O(log10(n)), where n is the input number. This is because in each step, we are dividing the number by 10, which reduces the number of digits by one. Therefore, the number of steps required to calculate the sum of cubes of digits is proportional to the number of digits in the number, which is log10(n).

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int originalNumber = n;  // Store the original number for comparison
    int sumOfCubes = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        sumOfCubes += pow(lastDigit, 3);  // Cube of the digit and add to sum
        n = n / 10;
    }

    if (originalNumber == sumOfCubes) {
        cout << originalNumber << " is an Armstrong number." << endl;
    } else {
        cout << originalNumber << " is not an Armstrong number." << endl;
    }

    return 0;
}