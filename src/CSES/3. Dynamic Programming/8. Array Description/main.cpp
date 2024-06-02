#include <bits/stdc++.h>
const int MOD = 1e9 + 7;

using namespace std;

int count_ways(int i, int v, int n, int m, const vector<int>& x, vector<vector<int>>& memo) {
    if (i == n) {
        return 1;
    }
    if (memo[i][v] != -1) {
        return memo[i][v];
    }

    int result = 0;
    if (x[i] != 0) {
        if (abs(x[i] - v) <= 1) {
            // use count_ways only if the last value is set correctly
            // ie. difference between current value and last value set is 1
            result = count_ways(i + 1, x[i], n, m, x, memo);
        }
    } else {
        for (int new_v = max(1, v - 1); new_v <= min(v + 1, m); ++new_v) {
            result = (result + count_ways(i + 1, new_v, n, m, x, memo)) % MOD;
        }
    }

    memo[i][v] = result;
    return result;
}

int solve(int n, int m, const vector<int>& x) {
    vector<vector<int>> memo(n, vector<int>(m + 1, -1));

    if (x[0] == 0) {
        int result = 0;
        // If the first element is unknown, it can be set any value from 1 to m
        for (int v = 1; v <= m; ++v) {
            result = (result + count_ways(1, v, n, m, x, memo)) % MOD;
        }
        return result;
    } else {
        // If the first element is known, start with that value
        return count_ways(1, x[0], n, m, x, memo);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    cout << solve(n, m, x) << endl;
    return 0;
}
