/*
    ============================================================
    TOPIC   : Stacks & Queues - Basic
    PROBLEM : Valid Parentheses (check if brackets are balanced)
    ============================================================

    INTUITION:
    ----------
    - Brackets close in reverse order of how they open (LIFO), which is
      exactly what a stack models: push every opening bracket, and when
      a closing bracket appears it must match the most recently opened
      (i.e. the current top of the stack).

    STEPS:
    ----------
    1. If the string length is odd, it can never be balanced — return false early.
    2. Map each closing bracket to its matching opening bracket.
    3. Walk through the string: push opening brackets onto the stack.
    4. On a closing bracket, check the stack isn't empty and its top
       matches; if so pop, else return false.
    5. At the end, the string is valid only if the stack is empty
       (every opened bracket got closed).

    VARIATIONS TO REMEMBER:
    ----------
    - Minimum additions/removals to make parentheses valid — count
      unmatched brackets instead of just returning a boolean.
    - Longest valid parentheses substring — a harder DP/stack variant.

    TIME COMPLEXITY  : O(n) -> single pass through the string
    SPACE COMPLEXITY : O(n) -> stack can hold up to n opening brackets
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0)
            return false;

        stack<int> st;
        unordered_map<char, char> m;

        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';

        for (char& ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else if (!st.empty() && ch == m[st.top()]) {
                st.pop();
            } else {
                return false;
            }
        }

        return st.empty();
    }
};

int main() {
    return 0;
}