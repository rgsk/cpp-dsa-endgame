#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<int> coins(n);
    int max_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        max_sum += coins[i];
    }

    // Memoization table to store results of subproblems
    vector<int> memo(max_sum + 1, -1);
    vector<int> possible_sums;

    for (int i = n; i >= 0; i--) {
        auto prev = memo;
        for (int remaining = 0; remaining <= max_sum; remaining++) {
            if (remaining == 0) {
                memo[remaining] = 1;
                continue;
            }
            if (i == n) {
                memo[remaining] = 0;
                continue;
            }
            if (coins[i] <= remaining) {
                memo[remaining] = memo[remaining] || prev[remaining - coins[i]];
            }
        }
    }

    for (int sum = 1; sum <= max_sum; sum++) {
        if (memo[sum] == 1) {
            possible_sums.push_back(sum);
        }
    }

    // Output the results
    cout << possible_sums.size() << endl;
    for (int sum : possible_sums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
