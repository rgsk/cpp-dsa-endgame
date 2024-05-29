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
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> graph(n + 1);
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    vector<ll> distances(n + 1, LONG_MAX);
    distances[1] = 0;
    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dist > distances[node]) {
            continue;
        }
        for (auto [child_dist, child_node] : graph[node]) {
            ll new_distance = dist + child_dist;
            if (new_distance < distances[child_node]) {
                distances[child_node] = new_distance;
                pq.push({new_distance, child_node});
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        cout << distances[i] << " ";
    }
    cout << endl;
}