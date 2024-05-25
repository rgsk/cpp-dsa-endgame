#include <bits/stdc++.h>
using namespace std;

int solve(int total, int n, vector<int>& arr) {
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j <= total; j++) {
            if (j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (i == n) {
                dp[i][j] = INT_MAX;
                continue;
            }
            int not_used = dp[i + 1][j];
            if (arr[i] <= j) {
                int used = dp[i][j - arr[i]];
                if (used != INT_MAX) {
                    dp[i][j] = min(1 + used, not_used);
                } else {
                    dp[i][j] = not_used;
                }
            } else {
                dp[i][j] = not_used;
            }
        }
    }

    return dp[0][total];
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = solve(x, n, arr);
    if (res != INT_MAX) {
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
}
