#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& visited, vector<int>& path) {
    if (visited[node]) {
        return node;
    }
    visited[node] = true;
    for (int child : graph[node]) {
        int cycleNode = dfs(child, node, graph, visited, path);
        if (cycleNode && child != parent) {
            if (cycleNode != -1) {
                path.push_back(node);
                if (node == cycleNode) {
                    return -1;
                } else {
                    return cycleNode;
                }
            } else {
                return cycleNode;
            }
        }
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> visited(n + 1, 0);
    vector<int> path;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, 0, graph, visited, path)) {
                reverse(path.begin(), path.end());
                path.push_back(path[0]);
                cout << path.size() << endl;
                for (int v : path) {
                    cout << v << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
