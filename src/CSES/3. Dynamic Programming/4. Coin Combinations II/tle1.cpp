#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int solve(int idx, int remaining, int n, vector<int>& coins, vector<vector<int>>& dp) {
    if (remaining == 0) {
        return 1;
    }
    if (idx == n) {
        return 0;
    }
    if (dp[idx][remaining] != -1) {
        return dp[idx][remaining];
    }
    if (coins[idx] <= remaining) {
        dp[idx][remaining] = (solve(idx, remaining - coins[idx], n, coins, dp) +
                              solve(idx + 1, remaining, n, coins, dp)) %
                             mod;
    } else {
        dp[idx][remaining] = solve(idx + 1, remaining, n, coins, dp);
    }
    return dp[idx][remaining];
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
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    int res = solve(0, x, n, coins, dp);
    cout << res << endl;
}
