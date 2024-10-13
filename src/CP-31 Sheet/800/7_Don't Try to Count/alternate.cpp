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
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        int ops = 0;
        // if we start with single character
        // after 5 operations it's length would become 32 (1 -> 2 -> 4 -> 8 -> 16 -> 32)
        // s2 max length is 25, if s2 is still not in s1, it's impossible to find s2 in s1
        while (ops < 5 && s1.find(s2) == string::npos) {
            s1 += s1;
            ops++;
        }
        if (s1.find(s2) == string::npos) {
            cout << -1 << endl;
        } else {
            cout << ops << endl;
        }
    }
    return 0;
}