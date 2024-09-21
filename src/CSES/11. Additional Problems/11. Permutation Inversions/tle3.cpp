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
            ll result = 0;

            // Try placing the largest number in all positions and calculate the number of inversions
            for (int i = 0; i <= min(j, i - 1); ++i) {
                result = (result + dp[i - 1][j - i]) % MOD;
            }
            dp[i][j] = result;
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}