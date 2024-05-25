#include <bits/stdc++.h>
using namespace std;
void perm(int idx, int n, string s, set<string>& ans) {
    if (idx == n) {
        ans.insert(s);
        return;
    }
    for (int i = idx; i < n; i++) {
        swap(s[i], s[idx]);
        perm(idx + 1, n, s, ans);
        swap(s[i], s[idx]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    set<string> ans;
    perm(0, s.size(), s, ans);
    cout << ans.size() << endl;
    for (auto v : ans) {
        cout << v << endl;
    }
}
