#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, long long>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
    dist[1] = 0;
    int x = -1;

    // Relax edges n times to find any negative cycle
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (const auto& [a, b, c] : edges) {
            if (dist[b] > dist[a] + c) {
                dist[b] = dist[a] + c;
                parent[b] = a;
                x = b;
            }
        }
    }

    if (x == -1) {
        cout << "NO" << endl;
    } else {
        // // Trace back the negative cycle
        // see the image attached
        for (int i = 0; i < n; ++i) {
            x = parent[x];
        }

        vector<int> cycle;
        for (int v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES" << endl;
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
