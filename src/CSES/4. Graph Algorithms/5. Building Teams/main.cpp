#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int cur_set, vector<int>& assigned, vector<vector<int>>& graph) {
    if (assigned[node]) {
        return true;
    }
    assigned[node] = cur_set;
    for (int child : graph[node]) {
        if (assigned[child] == cur_set || !dfs(child, cur_set == 1 ? 2 : 1, assigned, graph)) {
            return false;
        }
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> assigned(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!dfs(i, 1, assigned, graph)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << assigned[i] << " ";
    }
    cout << endl;
}