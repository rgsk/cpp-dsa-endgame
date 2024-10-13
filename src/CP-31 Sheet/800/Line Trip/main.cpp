#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int previous = 0;
        int min_fuel = 0;
        for (int i = 0; i < n; i++) {
            int checkpoint;
            cin >> checkpoint;
            min_fuel = max(checkpoint - previous, min_fuel);
            previous = checkpoint;
        }
        min_fuel = max(2 * (x - previous), min_fuel);
        cout << min_fuel << endl;
    }
    return 0;
}