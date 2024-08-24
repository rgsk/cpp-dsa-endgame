#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        int c = (a + b) % mod;
        a = b;
        b = c;
    }
    cout << a << endl;
}