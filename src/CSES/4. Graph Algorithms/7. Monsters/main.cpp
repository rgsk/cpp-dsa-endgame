#include <bits/stdc++.h>
using namespace std;
const vector<tuple<int, int, char>> ops = {
    {-1, 0, 'U'},
    {1, 0, 'D'},
    {0, -1, 'L'},
    {0, 1, 'R'},
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<char>> pathTaken(n, vector<char>(m));

    queue<pair<pair<int, int>, bool>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'M') {
                q.push({{i, j}, true});
            }
        }
    }
    int psi;
    int psj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'A') {
                q.push({{i, j}, false});
                psi = i;
                psj = j;
                break;
            }
        }
    }

    auto isBoundary = [&](int i, int j) {
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
            return true;
        }
        return false;
    };
    while (!q.empty()) {
        auto [pos, isMonster] = q.front();
        q.pop();
        auto [i, j] = pos;
        if (!isMonster && isBoundary(i, j)) {
            cout << "YES" << endl;
            int ni = i;
            int nj = j;
            string path;
            while (!(ni == psi && nj == psj)) {
                path += pathTaken[ni][nj];
                if (pathTaken[ni][nj] == 'U')
                    ni++;
                else if (pathTaken[ni][nj] == 'D')
                    ni--;
                else if (pathTaken[ni][nj] == 'L')
                    nj++;
                else if (pathTaken[ni][nj] == 'R')
                    nj--;
            }
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            cout << path << endl;
            return 0;
        }
        for (auto& op : ops) {
            int ni = i + get<0>(op);
            int nj = j + get<1>(op);
            if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                if (graph[ni][nj] == '.') {
                    graph[ni][nj] = isMonster ? 'M' : 'A';
                    q.push({{ni, nj}, isMonster});
                    if (!isMonster) {
                        pathTaken[ni][nj] = get<2>(op);
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}
