#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    ll ans = 0;
    unordered_map<ll, int> mp;
    mp[0] = 1;
    int x = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        x = (x + v) % n;
        ans += mp[x];
        mp[x]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    cout << ans << endl;
}