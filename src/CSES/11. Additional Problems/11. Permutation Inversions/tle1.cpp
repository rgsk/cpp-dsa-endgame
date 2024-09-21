#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

vector<vector<ll>> dp;

// Memoized function to calculate the number of permutations of size `n` with `k` inversions
ll count_permutations(int n, int k) {
    // Base cases
    if (n == 0) return k == 0;  // Only 1 way to arrange 0 elements (with 0 inversions)

    // If result is already computed, return the memoized value
    if (dp[n][k] != -1) return dp[n][k];

    ll result = 0;

    // Try placing the largest number in all positions and calculate the number of inversions
    for (int i = 0; i <= min(k, n - 1); ++i) {
        result = (result + count_permutations(n - 1, k - i)) % MOD;
    }

    // Store the result in the dp array (memoization)
    return dp[n][k] = result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, K;
    cin >> N >> K;

    // Initialize the dp table with -1 (indicating uncomputed states)
    dp = vector<vector<ll>>(N + 1, vector<ll>(K + 1, -1));

    // Output the result of the memoized function
    cout << count_permutations(N, K) << endl;

    return 0;
}