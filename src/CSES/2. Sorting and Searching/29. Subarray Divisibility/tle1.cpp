#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    vector<int> prefix_sum(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + vec[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if ((prefix_sum[j] - prefix_sum[i]) % n == 0) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
}
