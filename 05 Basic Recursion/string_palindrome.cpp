/*
    ============================================================
    TOPIC   : Basic Recursion
    PROBLEM : Check if a String is a Palindrome (using recursion)
    ============================================================

    INTUITION:
    ----------
    - A string is a palindrome if its first and last characters match,
      AND the substring between them (excluding those two) is also a
      palindrome. This is the recursive definition - shrink the window
      inward from both ends.

    STEPS:
    ----------
    1. Base case: if start >= end, the pointers have crossed/met - the
       remaining substring is trivially a palindrome, return true.
    2. If str[start] != str[end], mismatch found - return false immediately.
    3. Otherwise, recurse inward: checkPalindrome(str, start+1, end-1).

    VARIATIONS TO REMEMBER:
    ----------
    - Iterative two-pointer version does the same thing with a while loop -
      no recursion overhead, preferred for large strings.
    - Same "shrink from both ends" pattern is useful for reversing a
      string in place or checking array palindromes.

    TIME COMPLEXITY  : O(n) -> each call checks one pair of characters, n/2 calls total
    SPACE COMPLEXITY : O(n) -> recursion call stack depth (also string passed by value adds copies)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str, int start, int end){
    if(start >= end)
        return true;

    if(str[start] != str[end])
        return false;

    return checkPalindrome(str, start+1, end-1);
}

int main()
{
    string str1 = "racecar";
    cout << checkPalindrome(str1, 0, str1.length()-1) << endl;

    string str2 = "moma";
    cout << checkPalindrome(str2, 0, str2.length()-1) << endl;

    return 0;
}