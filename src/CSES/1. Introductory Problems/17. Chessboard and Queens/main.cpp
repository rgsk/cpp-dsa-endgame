#include <bits/stdc++.h>
using namespace std;

int total = 0;

bool issafe(int r, int c, vector<vector<char>>& board) {
    for (int i = 0; i <= r; i++) {
        if (board[i][c] == 'Q') return false;
        if (c - i >= 0 && board[r - i][c - i] == 'Q') return false;
        if (c + i < 8 && board[r - i][c + i] == 'Q') return false;
    }
    return true;
};

void solve(int r, vector<vector<char>>& board) {
    if (r == 8) {
        total++;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (issafe(r, c, board) && board[r][c] != '*') {
            board[r][c] = 'Q';
            solve(r + 1, board);
            board[r][c] = '.';
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<char>> vec(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> vec[i][j];
        }
    }
    solve(0, vec);
    cout << total << endl;
}
