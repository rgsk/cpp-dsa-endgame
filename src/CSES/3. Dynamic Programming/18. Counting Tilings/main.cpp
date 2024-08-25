#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

void generate_next_masks(int current_mask, int i, int next_mask, int n, vector<int>& next_masks) {
    if (i == n + 1) {
        next_masks.push_back(next_mask);
        return;
    }

    // If the current position is already covered, move to the next
    if ((current_mask & (1 << i)) != 0)
        generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);

    // Try placing a horizontal tile if possible
    if (i != n && (current_mask & (1 << i)) == 0 && (current_mask & (1 << (i + 1))) == 0)
        generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);

    // Try placing a vertical tile if possible
    if ((current_mask & (1 << i)) == 0)
        generate_next_masks(current_mask, i + 1, next_mask + (1 << i), n, next_masks);
}

int dp[1001][1 << 11];  // n is max 10, so 2^11 = 2048 possible masks

int solve(int col, int mask, const int m, const int n) {
    // Base case: If we've processed all columns
    if (col == m + 1) {
        return (mask == 0) ? 1 : 0;
    }

    // Memoization check
    if (dp[col][mask] != -1)
        return dp[col][mask];

    int answer = 0;
    vector<int> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);

    for (int next_mask : next_masks) {
        answer = (answer + solve(col + 1, next_mask, m, n)) % mod;
    }

    return dp[col][mask] = answer;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0, m, n);

    return 0;
}