#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long v;
    cin >> v;
    string ans;
    while (v > 0) {
        int digit = v % 10;
        if (digit >= 5 && !(digit == 9 && v < 10)) {
            ans += to_string(9 - digit);
        } else {
            ans += to_string(digit);
        }
        v /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}