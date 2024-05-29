#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;

int exp(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        int res = exp(a, b / 2);
        res = (1LL * res * res) % mod;  // Apply mod after squaring
        if (b % 2 != 0) {
            res = (1LL * res * a) % mod;  // Apply mod after multiplication with 'a'
        }
        return res;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll total = (n * (n + 1)) / 2;
    if (total % 2 == 0) {
        ll halfSum = total / 2;
        vector<ll> dp(halfSum + 1, -1);
        for (ll value = n + 1; value >= 1; value--) {
            auto prev = dp;
            for (ll remaining = 0; remaining <= halfSum; remaining++) {
                if (value == n + 1) {
                    if (remaining == 0) {
                        dp[remaining] = 1;
                    } else {
                        dp[remaining] = 0;
                    }
                    continue;
                }
                if (remaining >= value) {
                    dp[remaining] = (prev[remaining - value] + prev[remaining]) % mod;
                }
            }
        }
        ll res = dp[halfSum];
        cout << (res * exp(2, mod - 2)) % mod << endl;
    } else {
        cout << 0 << endl;
    }
}
