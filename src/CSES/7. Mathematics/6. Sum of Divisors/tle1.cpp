#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x;
    cin >> x;
    int total = 0;
    for (int j = 1; j <= x; j++) {
        for (int i = 1; i <= sqrt(j); i++) {
            if (j % i == 0) {
                total = (total + i) % mod;
                if (i != j / i) {
                    total = (total + (j / i)) % mod;
                }
            }
        }
    }

    cout << total << endl;
}
