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
        int v;
        cin >> v;
        if (v % 3 == 0) {
            cout << "Second" << endl;
        } else {
            cout << "First" << endl;
        }
    }
    return 0;
}