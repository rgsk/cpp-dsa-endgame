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
        int max_consecutive_dots = 0;
        int consecutive_dots = 0;
        int total_dots = 0;
        for (int i = 0; i < n; i++) {
            char v;
            cin >> v;
            if (v == '.') {
                total_dots++;
                consecutive_dots++;
                max_consecutive_dots = max(consecutive_dots, max_consecutive_dots);
            } else {
                consecutive_dots = 0;
            }
        }
        if (max_consecutive_dots >= 3) {
            cout << 2 << endl;
        } else {
            cout << total_dots << endl;
        }
    }
    return 0;
}