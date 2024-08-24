#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;

int ways(int remaining) {
    if (remaining == 0) return 1;
    int total = 0;
    for (int dice = 1; dice <= 6; dice++) {
        if (remaining >= dice) {
            total = (total + ways(remaining - dice)) % mod;
        }
    }
    return total;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n;
    cin >> n;
    cout << ways(n) << endl;
}