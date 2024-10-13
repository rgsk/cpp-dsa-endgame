#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int ans = 1e5;
    while (n--) {
        int v;
        cin >> v;
        ans = min(ans, abs(v));
    }
    cout << ans << endl;
    return 0;
}