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
        int s1_initial_length = s1.size();
        int ops = 0;
        // s1.size() - s1_initial_length + 1 < s2.size()
        // this condition checks whether we can achieve s2 length starting with last character of first s1
        // because s2 could start at any index of first s1 only (starting later is reduntant)
        while (s1.size() - s1_initial_length + 1 < s2.size() && s1.find(s2) == string::npos) {
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