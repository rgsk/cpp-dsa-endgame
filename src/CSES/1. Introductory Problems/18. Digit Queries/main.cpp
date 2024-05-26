#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    long long max_k = 25;
    string s;
    int v = 1;
    while (s.size() < max_k) {
        s += to_string(v);
        v += 1;
    }
    while (t--) {
        int i;
        cin >> i;
        cout << s[i - 1] << endl;
    }
}
