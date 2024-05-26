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
    vector<int> dp(x + 1, -1);
    for (int idx = n; idx >= 0; idx--) {
        auto prev = dp;
        for (int remaining = 0; remaining <= x; remaining++) {
            if (idx == n || remaining == 0) {
                dp[remaining] = 0;
                continue;
            }
            int take = 0;
            if (prices[idx] <= remaining) {
                take = pages[idx] + prev[remaining - prices[idx]];
            }
            int notake = prev[remaining];
            dp[remaining] = max(take, notake);
        }
    }
    int ans = dp[x];
    cout << ans << endl;
}
