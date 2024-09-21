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

    for (int n = 0; n <= N; n++) {
        for (int k = 0; k <= K; k++) {
            if (n == 0) {
                dp[n][k] = k == 0;
                continue;
            }
            ll result = 0;

            // Try placing the largest number in all positions and calculate the number of inversions
            for (int i = 0; i <= min(k, n - 1); ++i) {
                result = (result + dp[n - 1][k - i]) % MOD;
            }
            dp[n][k] = result;
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}