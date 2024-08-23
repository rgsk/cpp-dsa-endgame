// video
// https://www.youtube.com/watch?v=ZeRewE1Ks5Q

#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int h, v, ph;
        h = -1;
        v = -1;

        // write iterative
        for (int i = n; i >= 1; i--) {
            if (i == n) {
                h = 1;
                v = 1;
                continue;
            }
            ph = h;
            h = (2LL * h + v) % MOD;
            v = (4LL * v + ph) % MOD;
        }

        int result = (h + v) % MOD;
        cout << result << endl;
    }

    return 0;
}