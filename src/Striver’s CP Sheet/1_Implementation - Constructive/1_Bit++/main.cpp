#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int v = 0;
    while (n--) {
        string s;
        cin >> s;
        if (s == "++X" || s == "X++") {
            v++;
        } else {
            v--;
        }
    }
    cout << v << endl;
    return 0;
}