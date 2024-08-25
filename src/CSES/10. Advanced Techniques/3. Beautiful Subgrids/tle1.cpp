#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    // Reading the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    long long count = 0;

    // For each pair of rows
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int pairs = 0;

            // Count the number of valid column pairs (c1, c2)
            for (int c = 0; c < n; c++) {
                if (grid[i][c] == 1 && grid[j][c] == 1) {
                    pairs++;
                }
            }

            // The number of subgrids formed by this row pair (i, j) is pairs choose 2
            count += (pairs * (pairs - 1)) / 2;
        }
    }

    cout << count << endl;

    return 0;
}