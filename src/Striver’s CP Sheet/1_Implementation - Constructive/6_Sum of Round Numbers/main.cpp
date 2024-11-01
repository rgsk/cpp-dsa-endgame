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
        int m = 1;
        vector<int> ans;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            if (d > 0) {
                ans.push_back(d * m);
            }
            m *= 10;
        }
        cout << ans.size() << endl;
        for (int v : ans) {
            cout << v << ' ';
        }
        cout << endl;
    }
    return 0;
}