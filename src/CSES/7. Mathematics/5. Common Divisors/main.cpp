#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    const int max_x = 1e6;
    vector<int> freq(max_x);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    vector<int> multiples(max_x);
    for (int i = 1; i <= max_x; i++) {
        for (int j = i; j <= max_x; j += i) {
            if (freq[j]) {
                multiples[i] += freq[j];
            }
        }
    }
    int ans = 1;
    for (int i = 1; i <= max_x; i++) {
        if (multiples[i] > 1) {
            ans = max(ans, i);
        }
    }
    cout << ans << endl;
}
