// video
// https://www.youtube.com/watch?v=ZeRewE1Ks5Q

#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

vector<vector<int>> dp(1e6 + 1, vector<int>(2, -1));

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Re-initialize the dp array for each test case
        fill(dp.begin(), dp.end(), vector<int>(2, -1));

        // write iterative
        for (int i = n; i >= 1; i--) {
            if (i == n) {
                dp[i][0] = 1;
                dp[i][1] = 1;
                continue;
            }
            dp[i][0] = (2LL * dp[i + 1][0] + dp[i + 1][1]) % MOD;
            dp[i][1] = (4LL * dp[i + 1][1] + dp[i + 1][0]) % MOD;
        }

        int result = (dp[1][0] + dp[1][1]) % MOD;
        cout << result << endl;
    }

    return 0;
}