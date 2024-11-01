#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int count = 0;
    for (char c : s) {
        if (c == '4' || c == '7') {
            count++;
        }
    }
    if (count == 4 || count == 7) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}