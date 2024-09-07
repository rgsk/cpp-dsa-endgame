#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        function<bool(int)> helper = [&](int i) {
            if (i == n) {
                return true;
            }
            for (string word : wordDict) {
                if (i + word.size() <= n && s.substr(i, word.size()) == word) {
                    if (helper(i + word.size())) {
                        return true;
                    }
                }
            }
            return false;
        };
        return helper(0);
    }
};

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution sol;
    bool ans = sol.wordBreak(s, wordDict);
    cout << ans << endl;
    return 0;
}