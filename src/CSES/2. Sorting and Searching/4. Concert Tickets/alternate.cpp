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
        if (tickets.size() == 0) {
            cout << -1 << endl;
            continue;
        }
        auto it = tickets.lower_bound(bid);
        if (it == tickets.end()) {
            it--;
            cout << *it << endl;
            tickets.erase(it);
        } else if (*it == bid) {
            cout << *it << endl;
            tickets.erase(it);
        } else {
            // *it > bid
            if (it == tickets.begin()) {
                // we don't have a smaller value
                cout << -1 << endl;
            } else {
                // we have a smaller value
                it--;
                cout << *it << endl;
                tickets.erase(it);
            }
        }
    }
}
