#include <bits/stdc++.h>
using namespace std;

const vector<tuple<int, int, char>> ops = {
    {-1, 0, 'U'},
    {1, 0, 'D'},
    {0, -1, 'L'},
    {0, 1, 'R'},
};
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<char>> path(n, vector<char>(m));
    int start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'A') {
                start = i;
                end = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({start, end});
    graph[start][end] = '#';
    int steps = 0;

    while (!q.empty()) {
        int len = q.size();
        steps += 1;
        for (int v = 0; v < len; v++) {
            auto [i, j] = q.front();
            q.pop();
            for (auto& op : ops) {
                int ni = i + get<0>(op);
                int nj = j + get<1>(op);
                if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                    if (graph[ni][nj] == '.') {
                        q.push({ni, nj});
                        path[ni][nj] = get<2>(op);
                    } else if (graph[ni][nj] == 'B') {
                        path[ni][nj] = get<2>(op);
                        cout << "YES" << endl;
                        cout << steps << endl;
                        string complete_path;
                        pii P = {ni, nj};
                        while (steps > 0) {
                            auto [x, y] = P;
                            if (path[x][y] == 'D') {
                                P = {x - 1, y};
                            } else if (path[x][y] == 'U') {
                                P = {x + 1, y};
                            } else if (path[x][y] == 'L') {
                                P = {x, y + 1};
                            } else {
                                P = {x, y - 1};
                            }
                            complete_path += path[x][y];
                            steps--;
                        }
                        reverse(complete_path.begin(), complete_path.end());
                        cout << complete_path << endl;
                        return 0;
                    }
                    graph[ni][nj] = '#';
                }
            }
        }
    }
    cout << "NO" << endl;
}
