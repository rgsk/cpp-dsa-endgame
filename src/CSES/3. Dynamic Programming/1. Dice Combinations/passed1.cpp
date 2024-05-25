#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int solve(int n, vector<int>& dp) {
    if (n == 0) {
        return 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int total = 0;
    for (int i = 1; i <= min(6, n); i++) {
        total = (total + solve(n - i, dp)) % mod;
    }
    return dp[n] = total;
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    int res = solve(n, dp);
    cout << res << endl;
}
