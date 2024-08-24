#include <bits/stdc++.h>
using namespace std;

// write the recursive code

int maxProfit(vector<tuple<int, int, int>>& projects, int i, int n, int last) {
    if (i == n) {
        return 0;
    }
    int s, e, p;
    tie(s, e, p) = projects[i];
    if (s > last) {
        return max(p + maxProfit(projects, i + 1, n, e), maxProfit(projects, i + 1, n, last));
    }
    return maxProfit(projects, i + 1, n, last);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<tuple<int, int, int>> projects(n);
    for (int i = 0; i < n; i++) {
        int s, e, p;
        cin >> s >> e >> p;
        projects[i] = {s, e, p};
    }
    sort(projects.begin(), projects.end());
    cout << maxProfit(projects, 0, n, 0) << endl;
}