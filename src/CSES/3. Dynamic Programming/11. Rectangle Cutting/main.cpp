#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0;  // No cuts needed if the rectangle is already a square
            } else {
                int min_moves = INT_MAX;
                // Horizontal cuts
                for (int k = 1; k < i; ++k) {
                    min_moves = min(min_moves, 1 + dp[k][j] + dp[i - k][j]);
                }
                // Vertical cuts
                for (int k = 1; k < j; ++k) {
                    min_moves = min(min_moves, 1 + dp[i][k] + dp[i][j - k]);
                }
                dp[i][j] = min_moves;
            }
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}