#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int max_e = 0;
    vector<tuple<int, int, int>> projects(n);
    for (int i = 0; i < n; i++) {
        int s, e, p;
        cin >> s >> e >> p;
        max_e = max(max_e, e);
        projects[i] = {s, e, p};
    }
    sort(projects.begin(), projects.end());
    // write dynamic programming solution
    vector<vector<int>> dp(n + 1, vector<int>(max_e + 1, -1));
    for (int i = n; i <= 0; i--) {
        for (int last = max_e; last <= 0; last--) {
            if (i == n) {
                dp[i][last] = 0;
                continue;
            }
            int s, e, p;
            tie(s, e, p) = projects[i];
            if (s > last) {
                dp[i][last] = max(p + dp[i + 1][e], dp[i + 1][last]);
            } else {
                dp[i][last] = dp[i + 1][last];
            }
        }
    }
    cout << dp[0][0] << endl;
}