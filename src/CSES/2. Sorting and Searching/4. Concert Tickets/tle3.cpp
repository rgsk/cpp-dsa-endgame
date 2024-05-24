#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    vector<int> t(m);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    sort(h.begin(), h.end());
    for (int v : t) {
        auto it = upper_bound(h.begin(), h.end(), v);

        if (it != h.begin()) {
            it--;
            cout << *it << endl;
            h.erase(it);
        } else {
            cout << -1 << endl;
        }
    }
}
