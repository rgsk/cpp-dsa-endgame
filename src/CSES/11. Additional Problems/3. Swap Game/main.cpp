#include <bits/stdc++.h>
using namespace std;

string target = "123456789";

int get_index(int i, int j) {
    return i * 3 + j;
}

int min_moves(string start) {
    if (start == target) return 0;

    queue<pair<string, int>> q;
    unordered_set<string> visited;
    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [current, moves] = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i + 1 < 3) {
                    swap(current[get_index(i, j)], current[get_index(i + 1, j)]);
                    if (current == target) return moves + 1;
                    if (!visited.count(current)) {
                        visited.insert(current);
                        q.push({current, moves + 1});
                    }
                    swap(current[get_index(i, j)], current[get_index(i + 1, j)]);
                }
                if (j + 1 < 3) {
                    swap(current[get_index(i, j)], current[get_index(i, j + 1)]);
                    if (current == target) return moves + 1;
                    if (!visited.count(current)) {
                        visited.insert(current);
                        q.push({current, moves + 1});
                    }
                    swap(current[get_index(i, j)], current[get_index(i, j + 1)]);
                }
            }
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string start = "";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num;
            cin >> num;
            start += to_string(num);
        }
    }

    cout << min_moves(start) << endl;

    return 0;
}