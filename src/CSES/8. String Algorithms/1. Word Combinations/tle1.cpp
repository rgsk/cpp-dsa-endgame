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

int solve(int startIndex, string& s, int n, vector<int>& dp) {
    if (startIndex == n) {
        return 1;
    }
    if (dp[startIndex] != -1) {
        return dp[startIndex];
    }
    int ans = 0;
    for (int i = 1; i <= n - startIndex; i++) {
        auto sub = s.substr(startIndex, i);
        if (trie.search(sub)) {
            ans = (ans + solve(startIndex + i, s, n, dp)) % mod;
        }
    }
    return dp[startIndex] = ans;
}

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
    cout << solve(0, s, n, dp) << endl;
}
