#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int total, int n, vector<int>& arr, vector<vector<int>>& dp) {
    if (total == 0) {
        return 0;
    }
    if (idx == n) {
        return INT_MAX;
    }
    if (dp[idx][total] != -1) {
        return dp[idx][total];
    }
    int not_used = solve(idx + 1, total, n, arr, dp);
    if (arr[idx] <= total) {
        int used = solve(idx, total - arr[idx], n, arr, dp);
        if (used != INT_MAX) {
            dp[idx][total] = min(1 + used, not_used);
        } else {
            dp[idx][total] = not_used;
        }
    } else {
        dp[idx][total] = not_used;
    }
    return dp[idx][total];
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
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int res = solve(0, x, n, arr, dp);
    if (res != INT_MAX) {
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
}
