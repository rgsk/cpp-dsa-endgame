#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
// Dijkstra's
int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> graph(n + 1);
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();
        if (node == n) {
            cout << dist << " ";
            k -= 1;
            if (k == 0) {
                return 0;
            }
        }
        for (auto [child_dist, child_node] : graph[node]) {
            ll new_distance = dist + child_dist;
            pq.push({new_distance, child_node});
        }
    }
}