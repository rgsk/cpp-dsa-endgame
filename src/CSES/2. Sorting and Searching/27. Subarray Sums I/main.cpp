#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int ans = 0;
    // SLIDING WINDOW
    int l = 0;
    int r = 0;
    int total = 0;
    while (r < n) {
        total += vec[r];
        while (l <= r && total > x) {
            total -= vec[l++];
        }
        if (total == x) {
            ans++;
        }
        r++;
    }
    cout << ans << endl;
}
