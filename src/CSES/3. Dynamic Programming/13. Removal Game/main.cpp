#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> memo;

long long maxScore(const vector<int>& x, int i, int j, const vector<long long>& prefixSum) {
    if (i == j) {
        return x[i];
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    long long sumIJ = prefixSum[j + 1] - prefixSum[i];
    long long takeLeft = sumIJ - maxScore(x, i + 1, j, prefixSum);
    long long takeRight = sumIJ - maxScore(x, i, j - 1, prefixSum);

    return memo[i][j] = max(takeLeft, takeRight);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    // Calculate prefix sums for quick sum calculations
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + x[i];
    }

    // Initialize memoization table
    memo.assign(n, vector<long long>(n, -1));

    cout << maxScore(x, 0, n - 1, prefixSum) << endl;

    return 0;
}