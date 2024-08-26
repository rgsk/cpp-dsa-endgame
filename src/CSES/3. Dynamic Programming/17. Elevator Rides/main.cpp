#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, x;
vector<int> weights;
vector<pair<int, int>> dp;  // (minimum rides, weight of the last ride)

pair<int, int> solve(int mask) {
    // Base case: If all people are accommodated
    if (mask == 0) return {1, 0};

    if (dp[mask].first != -1) return dp[mask];

    pair<int, int> best = {INF, INF};

    // Try placing each person in the current ride
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            pair<int, int> option = solve(mask ^ (1 << i));

            // If the person can fit in the last ride
            if (option.second + weights[i] <= x) {
                option.second += weights[i];
            } else {
                // Otherwise, start a new ride
                option.first += 1;
                option.second = weights[i];
            }

            // Take the minimum of all possible options
            best = min(best, option);
        }
    }

    return dp[mask] = best;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> x;
    weights.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    dp.assign(1 << n, {-1, -1});

    pair<int, int> answer = solve((1 << n) - 1);
    cout << answer.first << endl;
    return 0;
}