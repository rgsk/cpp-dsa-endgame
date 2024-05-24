#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int v1 = 2 * a - b;
        int v2 = 2 * b - a;
        if (v1 >= 0 && v1 % 3 == 0 && v2 >= 0 && v2 % 3 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
