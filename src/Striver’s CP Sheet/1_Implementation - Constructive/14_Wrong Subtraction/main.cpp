#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    while (k > 0) {
        if (n % 10 == 0) {
            n /= 10;
        } else {
            n -= 1;
        }
        k--;
    }
    cout << n << endl;
    return 0;
}