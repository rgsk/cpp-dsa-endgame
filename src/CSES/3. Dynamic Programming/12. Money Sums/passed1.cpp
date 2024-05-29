#include <iostream>
#include <set>
#include <vector>

using namespace std;

void find_possible_sums(const vector<int>& coins, int index, int current_sum, vector<vector<bool>>& memo, set<int>& possible_sums) {
    if (index == coins.size()) {
        if (current_sum > 0) {
            possible_sums.insert(current_sum);
        }
        return;
    }

    if (memo[index][current_sum]) {
        return;
    }

    memo[index][current_sum] = true;

    // Option 1: Do not include the current coin
    find_possible_sums(coins, index + 1, current_sum, memo, possible_sums);

    // Option 2: Include the current coin
    find_possible_sums(coins, index + 1, current_sum + coins[index], memo, possible_sums);
}

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
    vector<vector<bool>> memo(n, vector<bool>(max_sum + 1, false));
    set<int> possible_sums;

    // Start recursive function
    find_possible_sums(coins, 0, 0, memo, possible_sums);

    // Output the results
    cout << possible_sums.size() << endl;
    for (int sum : possible_sums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
