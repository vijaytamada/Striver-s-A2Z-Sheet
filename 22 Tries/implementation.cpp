/*
    ============================================================
    TOPIC   : Tries
    PROBLEM : Trie (Prefix Tree) - Implement insert / search / startsWith
    ============================================================

    INTUITION:
    ----------
    - A Trie stores strings letter by letter in a tree, where each path
      from the root spells out a prefix. Words that share a prefix
      share the same path, making prefix-based lookups fast.
    - Each node holds a map of children (one per next character) and a
      flag `isEnd` marking whether a complete word ends there (a node
      can be part of a longer word's path AND also be a valid word
      ending -- both at once).

    STEPS:
    ----------
    1. insert(word): walk from root, creating a child node for any
       character that doesn't exist yet; mark isEnd = true at the
       final node.
    2. search(word): walk from root following each character; if any
       character is missing, the word isn't present -> false. If the
       full path exists, return whether isEnd is true (not just that
       the path exists).
    3. startsWith(prefix): same walk as search, but return true as
       soon as the full path exists -- no need to check isEnd (a
       prefix doesn't need to be a complete word).

    VARIATIONS TO REMEMBER:
    ----------
    - implementation_2.cpp extends this with prefixCount/endCount to
      support counting duplicate words and erase() -- this file only
      tracks presence (isEnd), that one tracks counts.
    - Tries are the backbone of autocomplete, word search boards, and
      any problem needing prefix matching (e.g. Longest Word with All
      Prefixes).

    TIME COMPLEXITY  : O(L) per operation -> L = length of word/prefix
    SPACE COMPLEXITY : O(N*L) total -> N words of average length L,
                        worst case no shared prefixes
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Trie {
    class Node {
    public:
        bool isEnd;
        unordered_map<char, Node*> children;

        Node() {
            isEnd = false;
        }
    };

public:
    Node* root;
    Trie() {
        root = new Node;
    }

    void insert(string word) {
        Node* curr = root;
        for (auto ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new Node();
            }
            curr = curr->children[ch];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        Node* curr = root;
        for (auto ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (char ch : prefix) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    return 0;
}