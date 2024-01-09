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
    while (t > 0) {
        int n, removed;
        cin >> n >> removed;
        long long x = 1;
        while (n > 0) {
            int v;
            cin >> v;
            x *= v;
            n--;
        }
        if (2023 % x == 0) {
            // first number
            cout << "YES" << endl;
            cout << 2023 / x;
            while (removed > 1) {
                cout << ' ' << 1;
                removed--;
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
        t--;
    }
}
