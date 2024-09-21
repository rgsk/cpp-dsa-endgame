#include <bits/stdc++.h>
using namespace std;

string target = "123456789";

int get_index(int i, int j) {
    return i * 3 + j;
}
vector<string> get_neighbors(string current) {
    vector<string> ans;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i + 1 < 3) {
                swap(current[get_index(i, j)], current[get_index(i + 1, j)]);
                ans.push_back(current);
                swap(current[get_index(i, j)], current[get_index(i + 1, j)]);
            }
            if (j + 1 < 3) {
                swap(current[get_index(i, j)], current[get_index(i, j + 1)]);
                ans.push_back(current);
                swap(current[get_index(i, j)], current[get_index(i, j + 1)]);
            }
        }
    }
    return ans;
}

int min_moves(string start) {
    if (start == target) return 0;

    queue<pair<string, int>> q;
    unordered_set<string> visited;
    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        string current_state = current.first;
        int moves = current.second;

        for (string neighbor : get_neighbors(current_state)) {
            if (neighbor == target) return moves + 1;
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push({neighbor, moves + 1});
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