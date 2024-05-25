#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int solve(int remaining, vector<int>& coins, vector<int>& dp) {
    if (remaining == 0) {
        return 1;
    }
    if (dp[remaining] != -1) {
        return dp[remaining];
    }
    int ans = 0;
    for (int coin : coins) {
        if (coin <= remaining) {
            ans = (ans + solve(remaining - coin, coins, dp)) % mod;
        }
    }
    return dp[remaining] = ans;
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
    vector<int> dp(x + 1, -1);
    int res = solve(x, coins, dp);
    cout << res << endl;
}
