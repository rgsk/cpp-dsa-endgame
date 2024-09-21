#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, K;
    cin >> N >> K;

    // Initialize the dp table with -1 (indicating uncomputed states)
    vector<vector<ll>> dp = vector<vector<ll>>(N + 1, vector<ll>(K + 1, -1));

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (i == 0) {
                dp[i][j] = j == 0;
                continue;
            }

            // Transition: dp[i][j] = sum of dp[i-1][j-p] for p from 0 to min(j, i-1)
            dp[i][j] = dp[i - 1][j];  // Start with dp[i-1][j]
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;  // Add dp[i][j-1] to accumulate the prefix sum
            }
            if (j >= i) {
                dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;  // Subtract out-of-bound values for the sum
            }
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}
