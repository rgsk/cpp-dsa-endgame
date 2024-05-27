#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int previous, vector<vector<int> >& graph, vector<int>& dist) {
    for (int child : graph[node]) {
        if (child != previous) {
            dist[child] = dist[node] + 1;
            dfs(child, node, graph, dist);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int> > graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> dist(n + 1);
    dfs(1, 0, graph, dist);
    int max_dist_node = 0;
    for (int node = 1; node <= n; node++) {
        if (dist[node] > dist[max_dist_node]) {
            max_dist_node = node;
        }
    }
    dist[max_dist_node] = 0;
    dfs(max_dist_node, 0, graph, dist);
    max_dist_node = 0;
    for (int node = 1; node <= n; node++) {
        if (dist[node] > dist[max_dist_node]) {
            max_dist_node = node;
        }
    }
    cout << dist[max_dist_node] << endl;
}
