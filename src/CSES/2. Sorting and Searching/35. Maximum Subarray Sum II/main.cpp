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
    multiset<ll> mySet;
    for (int i = a; i <= b; i++) {
        mySet.insert(prefix_sum[i]);
    }
    ll best = *mySet.rbegin();
    for (int i = 1; i <= n - a; i++) {
        mySet.erase(prefix_sum[i + a - 1]);
        mySet.insert(prefix_sum[min(i + b, n)]);
        best = max(best, *mySet.rbegin() - prefix_sum[i]);
    }
    cout << best << endl;
}
