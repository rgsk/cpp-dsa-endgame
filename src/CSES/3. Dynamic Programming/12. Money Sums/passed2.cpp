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
    vector<vector<int>> memo(n + 1, vector<int>(max_sum + 1, -1));
    vector<int> possible_sums;

    for (int i = n; i >= 0; i--) {
        for (int remaining = 0; remaining <= max_sum; remaining++) {
            if (remaining == 0) {
                memo[i][remaining] = 1;
                continue;
            }
            if (i == n) {
                memo[i][remaining] = 0;
                continue;
            }
            if (coins[i] <= remaining) {
                memo[i][remaining] = memo[i + 1][remaining] || memo[i + 1][remaining - coins[i]];
            } else {
                memo[i][remaining] = memo[i + 1][remaining];
            }
        }
    }

    for (int sum = 1; sum <= max_sum; sum++) {
        for (int j = 0; j < n; j++) {
            if (memo[j][sum] == 1) {
                possible_sums.push_back(sum);
                break;
            }
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
