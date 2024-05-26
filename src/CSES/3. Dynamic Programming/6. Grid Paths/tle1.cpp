#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<char>>& graph, int n, vector<vector<int>>& dp) {
    if (i == n - 1 && j == n - 1 && graph[i][j] == '.') {
        return 1;
    }
    if (i == n || j == n || graph[i][j] == '*') {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;
    ans += solve(i + 1, j, graph, n, dp);
    ans += solve(i, j + 1, graph, n, dp);
    return ans;
}

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
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = solve(0, 0, graph, n, dp);
    cout << ans << endl;
}
