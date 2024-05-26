#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    for (int idx = n; idx >= 0; idx--) {
        for (int remaining = 0; remaining <= x; remaining++) {
            if (idx == n || remaining == 0) {
                dp[idx][remaining] = 0;
                continue;
            }
            int take = 0;
            if (prices[idx] <= remaining) {
                take = pages[idx] + dp[idx + 1][remaining - prices[idx]];
            }
            int notake = dp[idx + 1][remaining];
            dp[idx][remaining] = max(take, notake);
        }
    }
    int ans = dp[0][x];
    cout << ans << endl;
}
