#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        edges[i] = {a, b, x};
    }
    vector<long long> distances(n + 1, LONG_MIN);
    distances[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            if (distances[a] != LONG_MIN && distances[a] + wt > distances[b]) {
                distances[b] = distances[a] + wt;
            }
        }
    }
    vector<bool> part_of_cycle(n + 1);
    for (auto edge : edges) {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        if (distances[a] != LONG_MIN && distances[a] + wt > distances[b]) {
            // if we can still update the distance
            // we have a positive cycle
            part_of_cycle[b] = true;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            if (part_of_cycle[a]) {
                part_of_cycle[b] = true;
            }
        }
    }

    if (part_of_cycle[n]) {
        cout << -1 << endl;
    } else {
        cout << distances[n] << endl;
    }
}
