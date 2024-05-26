#include <bits/stdc++.h>

using namespace std;

class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
   private:
    TrieNode* root;

   public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << (trie.search("apple") ? "Found" : "Not found") << endl;                   // Output: Found
    cout << (trie.search("app") ? "Found" : "Not found") << endl;                     // Output: Not found
    cout << (trie.startsWith("app") ? "Starts with" : "Doesn't start with") << endl;  // Output: Starts with
    trie.insert("app");
    cout << (trie.search("app") ? "Found" : "Not found") << endl;  // Output: Found
    return 0;
}
