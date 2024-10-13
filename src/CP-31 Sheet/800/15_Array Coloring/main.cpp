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
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            total += x;
        }
        if (total % 2 == 0) {
            // here if we take even out remaining is even (if take odd out remaining is odd)
            cout << "YES" << endl;
        } else {
            // // here if we take odd out remaining is even (if take even out remaining is odd)
            cout << "NO" << endl;
        }
    }
    return 0;
}