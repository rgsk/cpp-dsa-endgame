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
        int total = 0;
        for (int i = 0; i < n - 1; i++) {
            int v;
            cin >> v;
            total += v;
        }
        cout << -total << endl;
    }
    return 0;
}