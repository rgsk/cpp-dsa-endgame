#include <bits/stdc++.h>
using namespace std;

int total = 0;
int n = 8;
vector<bool> col(n);
vector<bool> topRight(2 * n - 1);
vector<bool> topLeft(2 * n - 1);

bool issafe(int r, int c, vector<vector<char>>& board) {
    return !col[c] && !topRight[r + c] && !topLeft[r - c + (n - 1)];
};
void setVal(int r, int c, bool val) {
    col[c] = val;
    topRight[r + c] = val;
    topLeft[r - c + (n - 1)] = val;
}

void solve(int r, vector<vector<char>>& board) {
    if (r == n) {
        total++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (issafe(r, c, board) && board[r][c] != '*') {
            setVal(r, c, true);
            board[r][c] = 'Q';
            solve(r + 1, board);
            board[r][c] = '.';
            setVal(r, c, false);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<char>> vec(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }
    solve(0, vec);
    cout << total << endl;
}
