#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int solve(int total, int n, vector<int>& coins) {
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
    for (int idx = n; idx >= 0; idx--) {
        for (int remaining = 0; remaining <= total; remaining++) {
            if (remaining == 0) {
                dp[idx][remaining] = 1;
                continue;
            }
            if (idx == n) {
                dp[idx][remaining] = 0;
                continue;
            }
            if (coins[idx] <= remaining) {
                dp[idx][remaining] = (dp[idx][remaining - coins[idx]] +
                                      dp[idx + 1][remaining]) %
                                     mod;
            } else {
                dp[idx][remaining] = dp[idx + 1][remaining];
            }
        }
    }
    return dp[0][total];
}
int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int res = solve(x, n, coins);
    cout << res << endl;
}
