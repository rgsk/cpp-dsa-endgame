#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            dp[i] = 0;
            continue;
        }
        int steps = INT_MAX;
        int value = i;
        while (value > 0) {
            int digit = value % 10;
            value /= 10;
            if (digit > 0) {
                steps = min(steps, 1 + dp[i - digit]);
            }
        }
        dp[i] = steps;
    }
    cout << dp[n] << endl;
}
