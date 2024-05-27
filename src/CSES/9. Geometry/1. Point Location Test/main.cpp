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
        long long p1x, p1y, p2x, p2y, p3x, p3y;
        cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
        auto x = ((p3y - p2y) * (p2x - p1x)) / ((p2y - p1y) * 1.0) + p2x;
        if (p3x < x) {
            cout << "LEFT" << endl;
        } else if (p3x > x) {
            cout << "RIGHT" << endl;
        } else {
            cout << "TOUCH" << endl;
        }
    }
}
