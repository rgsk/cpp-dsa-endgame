#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// Trie node structure
struct TrieNode {
    TrieNode* children[2];

    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};

class Trie {
   public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert prefix XOR into Trie
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    // Find maximum XOR for current prefix XOR
    int getMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            // Try to take the opposite bit to maximize XOR
            if (node->children[1 - bit]) {
                maxXor |= (1 << i);
                node = node->children[1 - bit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }
};

int findMaxXorSubarray(vector<int>& arr) {
    Trie trie;
    int prefixXor = 0;
    int maxXor = INT_MIN;

    trie.insert(0);  // Insert initial 0 to handle the case when the entire subarray is considered.

    int left = 0, right = 0;

    for (right = 0; right < arr.size(); ++right) {
        prefixXor ^= arr[right];  // Compute the prefix XOR

        // Query the maximum XOR for the current prefix XOR
        maxXor = max(maxXor, trie.getMaxXor(prefixXor));

        // Insert the current prefix XOR into the Trie
        trie.insert(prefixXor);
    }

    return maxXor;
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << findMaxXorSubarray(arr) << endl;

    return 0;
}