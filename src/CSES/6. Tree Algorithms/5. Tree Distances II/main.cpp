#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int depth, vector<int>& distances, vector<vector<int>>& graph) {
    distances[node] = depth;
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, depth + 1, distances, graph);
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
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> distances(n + 1);
    for (int i = 1; i <= n; i++) {
        dfs(i, 0, 0, distances, graph);
        int totalDistance = 0;
        for (int i = 1; i <= n; i++) {
            totalDistance += distances[i];
        }
        cout << totalDistance << " ";
    }
    cout << endl;

    return 0;
}
