// video
// https://www.youtube.com/watch?v=ZeRewE1Ks5Q

#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

vector<vector<int>> dp(1e6 + 1, vector<int>(2, -1));

int countWays(int i, int type, int n) {
    if (i == n) {
        // Base case
        return 1;
    }

    if (dp[i][type] != -1) {
        return dp[i][type];
    }

    if (type == 0) {
        dp[i][0] = (2LL * countWays(i + 1, 0, n) + countWays(i + 1, 1, n)) % MOD;
    } else {
        dp[i][1] = (4LL * countWays(i + 1, 1, n) + countWays(i + 1, 0, n)) % MOD;
    }

    return dp[i][type];
}

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

        int result = (countWays(1, 0, n) + countWays(1, 1, n)) % MOD;
        cout << result << endl;
    }

    return 0;
}