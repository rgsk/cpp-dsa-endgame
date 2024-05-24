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
    multiset<int> h;
    vector<int> t(m);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        h.insert(v);
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    for (int v : t) {
        auto it = h.upper_bound(v);

        if (it != h.begin()) {
            it--;
            cout << *it << endl;
            h.erase(it);
        } else {
            cout << -1 << endl;
        }
    }
}
