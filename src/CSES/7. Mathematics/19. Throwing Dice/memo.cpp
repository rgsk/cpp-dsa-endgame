#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;

int ways(int remaining, vector<int> &dp) {
    if (remaining == 0) return 1;
    if (dp[remaining] != -1) return dp[remaining];
    int total = 0;
    for (int dice = 1; dice <= 6; dice++) {
        if (remaining >= dice) {
            total = (total + ways(remaining - dice, dp)) % mod;
        }
    }
    return dp[remaining] = total;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << ways(n, dp) << endl;
}