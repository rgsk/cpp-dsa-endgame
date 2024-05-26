#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    ll ans = 0;
    ll total = 0;
    unordered_map<ll, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        total += v;
        ans += mp[total - x];
        mp[total]++;
    }
    cout << ans << endl;
}
