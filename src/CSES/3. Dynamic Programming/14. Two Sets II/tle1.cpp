#include <bits/stdc++.h>
using namespace std;

int solve(int value, int remaining, int n) {
    if (value == n + 1) {
        if (remaining == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (remaining >= value) {
        return solve(value + 1, remaining - value, n) + solve(value + 1, remaining, n);
    }
    return solve(value + 1, remaining, n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int total = n * (n + 1) / 2;
    if (total % 2 == 0) {
        int halfSum = total / 2;
        cout << solve(1, halfSum, n) / 2 << endl;
    } else {
        cout << 0 << endl;
    }
}
