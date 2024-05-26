#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<char>>& graph, int n, int m) {
    if (i >= 0 && j >= 0 && i < n && j < m && graph[i][j] == '.') {
        graph[i][j] = '#';
        dfs(i + 1, j, graph, n, m);
        dfs(i - 1, j, graph, n, m);
        dfs(i, j + 1, graph, n, m);
        dfs(i, j - 1, graph, n, m);
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
