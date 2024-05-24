// TLE

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
        while (a > 0 && b > 0) {
            if (a > b) {
                a -= 2;
                b -= 1;
            } else {
                a -= 1;
                b -= 2;
            }
        }
        if (a == 0 && b == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
