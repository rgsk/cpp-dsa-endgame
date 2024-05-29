#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// floyd warshall
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> graph(n + 1, vector<ll>(n + 1, LONG_MAX));
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int min_value = min(graph[a][b], 1LL * c);
        graph[a][b] = min_value;
        graph[b][a] = min_value;
    }
    // floyd warshall
    // the magic of floyd warshall is
    // no matter in which order k is processed
    // we would get the same result
    // bro try with examples
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] != LONG_MAX && graph[k][j] != LONG_MAX) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (graph[a][b] == LONG_MAX ? -1 : graph[a][b]) << endl;
    }
}
