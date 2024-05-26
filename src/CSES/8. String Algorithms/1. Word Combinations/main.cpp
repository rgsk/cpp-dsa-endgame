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
   public:
    TrieNode* root;
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

Trie trie;
const int mod = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        string c;
        cin >> c;
        trie.insert(c);
    }
    int n = s.size();
    vector<int> dp(n, -1);
    for (int startIndex = n; startIndex >= 0; startIndex--) {
        if (startIndex == n) {
            dp[startIndex] = 1;
            continue;
        }
        int ans = 0;
        auto current = trie.root;

        for (int i = 1; i <= n - startIndex; i++) {
            auto ch = s[startIndex + i - 1];
            if (current->children.find(ch) != current->children.end()) {
                current = current->children[ch];
            } else {
                break;
            }
            if (current->isEndOfWord) {
                ans = (ans + dp[startIndex + i]) % mod;
            }
        }
        dp[startIndex] = ans;
    }
    cout << dp[0] << endl;
}
