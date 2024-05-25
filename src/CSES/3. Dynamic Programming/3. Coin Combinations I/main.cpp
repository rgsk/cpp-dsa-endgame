#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int solve(int total, vector<int>& coins) {
    vector<int> dp(total + 1, -1);
    for (int remaining = 0; remaining <= total; remaining++) {
        if (remaining == 0) {
            dp[remaining] = 1;
            continue;
        }
        int ans = 0;
        for (int coin : coins) {
            if (coin <= remaining) {
                ans = (ans + dp[remaining - coin]) % mod;
            }
        }
        dp[remaining] = ans;
    }
    return dp[total];
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

    int res = solve(x, coins);
    cout << res << endl;
}
