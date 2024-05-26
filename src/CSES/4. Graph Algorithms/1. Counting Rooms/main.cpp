#include <bits/stdc++.h>
using namespace std;

void dfs(int l, int r, vector<vector<char>>& graph, int n, int m) {
    if (l >= 0 && r >= 0 && l < n && r < m && graph[l][r] == '.') {
        graph[l][r] = '#';
        dfs(l + 1, r, graph, n, m);
        dfs(l - 1, r, graph, n, m);
        dfs(l, r + 1, graph, n, m);
        dfs(l, r - 1, graph, n, m);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == '.') {
                rooms += 1;
                dfs(i, j, graph, n, m);
            }
        }
    }
    cout << rooms << endl;
}
