#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        long long ans;
        if (x > y) {
            if (x % 2 == 0) {
                ans = x * x - (y - 1);
            } else {
                x -= 1;
                ans = x * x + y;
            }
        } else {
            if (y % 2 == 1) {
                ans = y * y - (x - 1);
            } else {
                y -= 1;
                ans = y * y + x;
            }
        }
        cout << ans << endl;
    }
}
