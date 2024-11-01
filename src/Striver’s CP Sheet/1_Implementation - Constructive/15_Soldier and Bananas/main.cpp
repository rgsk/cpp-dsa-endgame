#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int k, n, w;
    cin >> k >> n >> w;
    int total = 0;
    for (int i = 1; i <= w; i++) {
        total += i * k;
    }
    cout << max(total - n, 0) << endl;
    return 0;
}