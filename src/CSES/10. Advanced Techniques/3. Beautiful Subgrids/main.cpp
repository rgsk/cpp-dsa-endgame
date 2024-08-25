#include <bitset>
#include <iostream>
#include <vector>
#pragma GCC target("popcnt")

using namespace std;

const int MAX_N = 3000;  // Maximum value for n
bitset<MAX_N> grid[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    // Reading the grid
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    long long count = 0;

    // For each pair of rows
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate the number of common set bits (1s) between row i and row j
            int common = (grid[i] & grid[j]).count();
            // The number of subgrids formed by this row pair (i, j) is common choose 2
            count += (common * (common - 1)) / 2;
        }
    }

    cout << count << endl;

    return 0;
}