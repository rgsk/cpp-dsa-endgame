#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int l = 0;
    int r = n - 1;
    int ans = 0;
    while (l <= r) {
        int c = 0;
        if (l + c <= r - c && p[l + c] + p[r] <= x) {
            c++;
        }
        if (c == 0) {
            r--;
            ans++;
        } else {
            l += c;
            r -= c;
            ans += c;
        }
    }
    cout << ans << endl;
}
