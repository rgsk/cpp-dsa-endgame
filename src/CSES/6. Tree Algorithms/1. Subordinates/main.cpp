#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& graph, int node, vector<int>& ans) {
    int total = 0;
    for (auto child : graph[node]) {
        total += 1 + solve(graph, child, ans);
    }
    ans[node] = total;
    return total;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<int> ans(n + 1);
    for (int i = 2; i <= n; i++) {
        int v;
        cin >> v;
        graph[v].push_back(i);
    }
    solve(graph, 1, ans);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
