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
        bool found = false;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            if (v == k) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}