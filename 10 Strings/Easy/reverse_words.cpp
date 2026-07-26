/*
    ============================================================
    TOPIC   : Strings - Easy
    PROBLEM : Reverse Words in a String
    ============================================================

    INTUITION:
    ----------
    - Reversing word ORDER (not the letters within each word) means each
      word extracted can simply be prepended to a growing result string.
    - Extra/leading/trailing spaces need to be skipped while splitting words.

    STEPS:
    ----------
    1. (Solution1, STL) Use stringstream to extract words one at a time;
       prepend each new word to res (res = word + " " + res), then trim the
       trailing extra space at the end.
    2. (Solution2, manual) Use two pointers i, j to find word boundaries:
       skip spaces, mark start (i), advance j to the next space, extract
       substr(i, j-i), prepend it to the answer, move i = j + 1, repeat.

    VARIATIONS TO REMEMBER:
    ----------
    - "Reverse words but keep original word order, reverse letters instead"
      is a different, easier problem - don't confuse the two.
    - In-place O(1) extra space version: reverse the whole string first,
      then reverse each word back - useful follow-up in interviews.

    TIME COMPLEXITY  : O(n) -> single pass building the result
    SPACE COMPLEXITY : O(n) -> result string storage
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Solution1 - Using STL
class Solution1 {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string res;
        while (ss >> word) {
            res = word + " " + res;
        }
        res.pop_back();
        return res;
    }
};

// Solution2 - Without using STL
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int j = 0;
        int i = 0;
        string ans = "";

        while (i < n) {
            // Skip any leading spaces
            while (i < n && s[i] == ' ')
                i++;

            if (i >= n) break; // End of string reached

            // Find the end of the current word
            j = i;
            while (j < n && s[j] != ' ')
                j++;

            // Extract the word
            string sub = s.substr(i, j - i);

            // Prepend the word to the result string
            if (ans.length() == 0)
                ans = sub;
            else
                ans = sub + " " + ans;

            // Move to the next word
            i = j + 1;
        }

        return ans;
    }
};

int main()
{
    

    return 0;
}