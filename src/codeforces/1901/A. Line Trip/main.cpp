// https://codeforces.com/problemset/problem/1901/A

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int max_diff = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            max_diff = max(max_diff, v - prev);
            prev = v;
        }
        max_diff = max(max_diff, (x - prev) * 2);
        cout << max_diff << endl;
    }
    return 0;
}
