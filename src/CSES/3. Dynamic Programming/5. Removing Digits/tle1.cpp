#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp) {
    if (n == 0) {
        return 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int steps = INT_MAX;
    int value = n;
    while (value > 0) {
        int digit = value % 10;
        value /= 10;
        if (digit > 0) {
            steps = min(steps, 1 + solve(n - digit, dp));
        }
    }
    return steps;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << solve(n, dp) << endl;
}
