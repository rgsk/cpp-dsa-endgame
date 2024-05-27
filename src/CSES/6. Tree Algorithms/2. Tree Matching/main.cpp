#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void dfs(int node, int previous, vector<vector<int>>& graph, vector<int>& used) {
    for (int child : graph[node])
        if (child != previous)
            dfs(child, node, graph, used);

    if (!used[previous] && !used[node] && previous != 0) {
        used[previous] = used[node] = true;
        cnt++;
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
    vector<int> used(n + 1);
    dfs(1, 0, graph, used);
    cout << cnt << endl;
}
