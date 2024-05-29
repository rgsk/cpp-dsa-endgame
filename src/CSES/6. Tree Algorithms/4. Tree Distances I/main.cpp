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

int find_farthest_node(int n, vector<int>& distances) {
    int farthest_node = 1;
    int max_distance = -1;
    for (int i = 1; i <= n; i++) {
        if (distances[i] > max_distance) {
            max_distance = distances[i];
            farthest_node = i;
        }
    }
    return farthest_node;
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
    vector<int> distances_u(n + 1);
    vector<int> distances_v(n + 1);

    // First DFS from any node (let's start from node 1)
    dfs(1, 0, 0, distances, graph);

    // Find the farthest node from node 1, call it u
    int u = find_farthest_node(n, distances);

    // Second DFS from node u
    dfs(u, 0, 0, distances_u, graph);

    // Find the farthest node from u, call it v
    int v = find_farthest_node(n, distances_u);

    // Third DFS from node v
    dfs(v, 0, 0, distances_v, graph);

    // Compute the result for each node
    for (int i = 1; i <= n; i++) {
        cout << max(distances_u[i], distances_v[i]) << " ";
    }

    return 0;
}
