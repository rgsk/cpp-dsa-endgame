#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<char>> graph(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int i = n; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == n || j == n || graph[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            if (i == n - 1 && j == n - 1 && graph[i][j] == '.') {
                dp[i][j] = 1;
                continue;
            }
            int ans = 0;
            ans += dp[i + 1][j];
            ans += dp[i][j + 1];
            dp[i][j] = ans % mod;
        }
    }
    cout << dp[0][0] << endl;
}
