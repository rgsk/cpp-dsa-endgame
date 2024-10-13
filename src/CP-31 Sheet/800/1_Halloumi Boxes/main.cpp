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
        int n, k;
        cin >> n >> k;
        bool is_sorted = true;
        int last = INT_MIN;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x < last) {
                is_sorted = false;
            }
            last = x;
        }
        if (is_sorted || k >= 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}