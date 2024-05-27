#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ll> prefix_sum(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
    }
    ll maxSum = LONG_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i + a; j <= min(i + b, n); j++) {
            ll subarraySum = prefix_sum[j] - prefix_sum[i];
            maxSum = max(maxSum, subarraySum);
        }
    }
    cout << maxSum << endl;
}
