#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string word1, word2;
    cin >> word1 >> word2;
    int lenWord2 = word2.size();
    int lenWord1 = word1.size();
    vector<vector<int>> dp(lenWord1 + 1, vector<int>(lenWord2 + 1, -1));
    function<int(int, int)> solve = [&](int i, int j) {
        if (i == lenWord1) {
            return lenWord2 - j;
        }
        if (j == lenWord2) {
            return lenWord1 - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(i + 1, j + 1);
        } else {
            // remove, replace, add respectively
            return dp[i][j] = 1 + min({solve(i + 1, j), solve(i + 1, j + 1), solve(i, j + 1)});
        }
    };
    int result = solve(0, 0);
    cout << result << endl;
}