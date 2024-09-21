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
    multiset<int> tickets;
    vector<int> bids(m);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        tickets.insert(v);
    }
    for (int i = 0; i < m; i++) {
        cin >> bids[i];
    }
    for (int bid : bids) {
        auto it = tickets.lower_bound(bid);
        if (it != tickets.end() && *it == bid) {
            cout << *it << endl;
            tickets.erase(it);
        } else {
            // we have a smaller value
            if (it != tickets.begin()) {
                it--;
                cout << *it << endl;
                tickets.erase(it);
            } else {
                cout << -1 << endl;
            }
        }
    }
}
