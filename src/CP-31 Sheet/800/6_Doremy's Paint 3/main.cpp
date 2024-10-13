#include <bits/stdc++.h>
using namespace std;

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
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            mp[v]++;
        }
        if (mp.size() == 1) {
            cout << "YES" << endl;
        } else if (mp.size() == 2) {
            if (abs(mp.begin()->second - next(mp.begin())->second) <= 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}