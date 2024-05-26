#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int remaining, vector<int>& prices, vector<int>& pages, int n) {
    if (idx == n) {
        return 0;
    }
    if (remaining == 0) {
        return 0;
    }
    int take = 0;
    if (prices[idx] <= remaining) {
        take = pages[idx] + solve(idx + 1, remaining - prices[idx], prices, pages, n);
    }
    int notake = solve(idx + 1, remaining, prices, pages, n);
    return max(take, notake);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    int ans = solve(0, x, prices, pages, n);
    cout << ans << endl;
}
