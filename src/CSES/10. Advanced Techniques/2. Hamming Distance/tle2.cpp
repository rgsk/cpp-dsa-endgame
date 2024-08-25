#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; j < k; j++) {
            char c;
            cin >> c;
            mask = mask * 2 + (c == '1');
        }
        a[i] = mask;
    }

    int minHamming = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = 0;
            for (int bit = 0; bit < k; bit++) {
                if ((a[i] & (1 << bit)) != (a[j] & (1 << bit))) {
                    dist++;
                }
            }
            minHamming = min(minHamming, dist);
        }
    }
    cout << minHamming << endl;
}