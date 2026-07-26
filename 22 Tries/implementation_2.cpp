/*
    ============================================================
    TOPIC   : Tries
    PROBLEM : Trie with Count of Words Equal To / Starting With, and Erase
    ============================================================

    INTUITION:
    ----------
    - Extends the basic Trie by storing counts at each node instead of
      a boolean: `prefixCount` = how many words pass through this node
      (i.e., have this prefix), `endCount` = how many words end exactly
      here (handles duplicate word insertions correctly).
    - This lets us answer "how many words equal X" and "how many words
      start with X" directly, and support removing one occurrence of a
      word cleanly.

    STEPS:
    ----------
    1. insert(word): walk/create the path character by character,
       incrementing prefixCount at every node passed through;
       increment endCount at the final node.
    2. countWordsEqualTo(word): walk the path for word; if it fully
       exists, return endCount at the final node (0 if the path breaks
       early).
    3. countWordsStartingWith(prefix): walk the path for prefix; if it
       fully exists, return prefixCount at the final node (0 if the
       path breaks early).
    4. erase(word): walk the path, decrementing prefixCount at every
       node along the way, then decrement endCount at the final node
       (assumes the word is actually present -- no existence check
       before decrementing).

    VARIATIONS TO REMEMBER:
    ----------
    - Compare with implementation.cpp's simpler isEnd-boolean version --
      that one can't handle duplicate words or deletions.
    - prefixCount/endCount is the standard pattern for a Trie that
      supports counting and deletion, common in "Implement Trie II"
      style interview questions.

    TIME COMPLEXITY  : O(L) per operation -> L = length of word/prefix
    SPACE COMPLEXITY : O(N*L) total for storing N words of average length L
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Trie {
    class Node {
    public:
        unordered_map<char, Node*> children;
        int endCount;      // how many words end here
        int prefixCount;   // how many words pass through this node

        Node() {
            endCount = 0;
            prefixCount = 0;
        }
    };

private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert a word
    void insert(const string& word) {
        Node* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new Node();
            }
            curr = curr->children[ch];
            curr->prefixCount++;
        }
        curr->endCount++;
    }

    // Count words equal to given word
    int countWordsEqualTo(const string& word) {
        Node* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end())
                return 0;
            curr = curr->children[ch];
        }
        return curr->endCount;
    }

    // Count words starting with given prefix
    int countWordsStartingWith(const string& prefix) {
        Node* curr = root;
        for (char ch : prefix) {
            if (curr->children.find(ch) == curr->children.end())
                return 0;
            curr = curr->children[ch];
        }
        return curr->prefixCount;
    }

    // Erase one occurrence of a word
    void erase(const string& word) {
        Node* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end())
                return; // word not present
            curr = curr->children[ch];
            curr->prefixCount--;
        }
        curr->endCount--;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");

    cout << trie.countWordsEqualTo("apple") << endl;      // 2
    cout << trie.countWordsStartingWith("app") << endl;  // 3

    trie.erase("apple");

    cout << trie.countWordsEqualTo("apple") << endl;      // 1
    cout << trie.countWordsStartingWith("app") << endl;  // 2

    return 0;
}
