#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 7;
const int M = N * N - 1;
string path;
bool visited[N][N];

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && !visited[x][y];
}

int dfs(int x, int y, int step) {
    if (step == M || (x == N - 1 && y == 0)) {
        return step == M && (x == N - 1 && y == 0);
    }

    // Deadlock avoidance checks
    if ((isValid(x + 1, y) && isValid(x - 1, y)) &&
        (!isValid(x, y - 1) && !isValid(x, y + 1))) {
        // POINT:
        // If we can only go up and down, but not left or right
        // it means either upper side or lower side won't be covered
        return 0;
    }
    if ((isValid(x, y + 1) && isValid(x, y - 1)) &&
        (!isValid(x + 1, y) && !isValid(x - 1, y))) {
        // If we can only go left and right, but not up or down
        return 0;
    }

    visited[x][y] = true;
    int totalPaths = 0;

    char c = path[step];
    if ((c == 'D' || c == '?') && isValid(x + 1, y)) {
        totalPaths += dfs(x + 1, y, step + 1);
    }
    if ((c == 'U' || c == '?') && isValid(x - 1, y)) {
        totalPaths += dfs(x - 1, y, step + 1);
    }
    if ((c == 'L' || c == '?') && isValid(x, y - 1)) {
        totalPaths += dfs(x, y - 1, step + 1);
    }
    if ((c == 'R' || c == '?') && isValid(x, y + 1)) {
        totalPaths += dfs(x, y + 1, step + 1);
    }

    visited[x][y] = false;
    return totalPaths;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> path;

    memset(visited, false, sizeof(visited));

    cout << dfs(0, 0, 0) << endl;

    return 0;
}