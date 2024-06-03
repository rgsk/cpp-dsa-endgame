#include <bits/stdc++.h>
using namespace std;
const long long INF = numeric_limits<long long>::max();

struct Edge {
    int to;
    long long cost;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // Min-heap priority queue
    priority_queue<tuple<long long, int, bool>, vector<tuple<long long, int, bool>>, greater<tuple<long long, int, bool>>> pq;
    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));

    dist[1][0] = 0;
    pq.push({0, 1, false});

    while (!pq.empty()) {
        auto [d, u, usedCoupon] = pq.top();
        pq.pop();

        if (u == n) {
            cout << d << endl;
            return 0;
        }

        if (d > dist[u][usedCoupon]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            long long c = edge.cost;

            // Without using the coupon
            if (dist[v][usedCoupon] > d + c) {
                dist[v][usedCoupon] = d + c;
                pq.push({dist[v][usedCoupon], v, usedCoupon});
            }

            // Using the coupon
            if (!usedCoupon && dist[v][1] > d + c / 2) {
                dist[v][1] = d + c / 2;
                pq.push({dist[v][1], v, true});
            }
        }
    }

    return 0;
}
