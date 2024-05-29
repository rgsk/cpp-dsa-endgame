#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        graph[a].push_back({x, b});
    }
    priority_queue<pair<int, int>> q;
    q.push({0, 1});
    while (!q.empty()) {
        auto [acc_cost, node] = q.top();
        q.pop();
        for (auto [cost, child] : graph[node]) {
            if (child == n) {
                cout << acc_cost + cost << endl;
                return 0;
            }
            q.push({acc_cost + cost, child});
        }
    }
}
