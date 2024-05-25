#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int solve(int n) {
    vector<int> dp(n + 1, -1);
    for (int j = 0; j <= n; j++) {
        if (j == 0) {
            dp[j] = 1;
            continue;
        }
        int total = 0;
        for (int i = 1; i <= min(6, j); i++) {
            total = (total + dp[j - i]) % mod;
        }
        dp[j] = total;
    }
    return dp[n];
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
    int res = solve(n);
    cout << res << endl;
}
