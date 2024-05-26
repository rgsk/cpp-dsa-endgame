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
    for (int i = 1; i <= x; i++) {
        total = (total + (x / i) * i) % mod;
    }
    cout << total << endl;
}
