#include <bits/stdc++.h>
using namespace std;

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
    queue<int> q;
    q.push(1);
    vector<int> parent(n + 1);
    parent[1] = 1;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            int node = q.front();
            q.pop();
            for (int child : graph[node]) {
                if (!parent[child]) {
                    q.push(child);
                    parent[child] = node;
                    if (child == n) {
                        int cur = child;
                        vector<int> path;
                        while (cur != 1) {
                            path.push_back(cur);
                            cur = parent[cur];
                        }
                        path.push_back(1);
                        cout << path.size() << endl;
                        for (int j = path.size() - 1; j >= 0; j--) {
                            cout << path[j] << " ";
                        }
                        cout << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
