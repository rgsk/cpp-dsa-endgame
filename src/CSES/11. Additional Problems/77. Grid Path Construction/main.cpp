#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool is_even(int n, int m) {
    return (n * m) % 2 == 0;
}

void print_path(vector<string> &grid, int n, int m, int y1, int x1, int y2, int x2) {
    // Grid has dimensions n x m, and points a=(y1, x1), b=(y2, x2)
    string path = "";

    // Start from (y1, x1)
    int cur_y = y1, cur_x = x1;

    // Generate path in a zigzag manner, if possible
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {  // Left to right
            for (int j = 0; j < m; j++) {
                if (i == cur_y && j == cur_x) continue;  // Skip the start position
                path += (cur_y < i) ? "D" : ((cur_y > i) ? "U" : "");
                path += (cur_x < j) ? "R" : ((cur_x > j) ? "L" : "");
                cur_y = i;
                cur_x = j;
            }
        } else {  // Right to left
            for (int j = m - 1; j >= 0; j--) {
                if (i == cur_y && j == cur_x) continue;  // Skip the start position
                path += (cur_y < i) ? "D" : ((cur_y > i) ? "U" : "");
                path += (cur_x < j) ? "R" : ((cur_x > j) ? "L" : "");
                cur_y = i;
                cur_x = j;
            }
        }
    }

    // Manually add path to (y2, x2) if not already there
    if (cur_y != y2 || cur_x != x2) {
        while (cur_y != y2) {
            path += (cur_y < y2) ? "D" : "U";
            cur_y += (cur_y < y2) ? 1 : -1;
        }
        while (cur_x != x2) {
            path += (cur_x < x2) ? "R" : "L";
            cur_x += (cur_x < x2) ? 1 : -1;
        }
    }

    cout << path << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    while (t--) {
        int n, m, y1, x1, y2, x2;
        cin >> n >> m >> y1 >> x1 >> y2 >> x2;

        // Adjust to 0-based index
        y1--;
        x1--;
        y2--;
        x2--;

        // Special edge case: single row or column
        if (n == 1 || m == 1) {
            if (abs(x1 - x2) + abs(y1 - y2) == n * m - 1) {
                cout << "YES" << endl;
                print_path(vector<string>(n, string(m, '.')), n, m, y1, x1, y2, x2);
            } else {
                cout << "NO" << endl;
            }
            continue;
        }

        // General case for larger grids
        cout << "YES" << endl;
        print_path(vector<string>(n, string(m, '.')), n, m, y1, x1, y2, x2);
    }

    return 0;
}