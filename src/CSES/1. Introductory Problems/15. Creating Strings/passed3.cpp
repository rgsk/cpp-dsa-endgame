#include <bits/stdc++.h>
using namespace std;
void perm(int idx, int n, string s, vector<string>& ans) {
    if (idx == n) {
        ans.push_back(s);
        return;
    }
    unordered_set<char> seen;  // Set to track characters at current index
    for (int i = idx; i < n; i++) {
        if (seen.find(s[i]) != seen.end()) {
            continue;  // Skip duplicate characters
        }
        seen.insert(s[i]);  // Mark character as seen
        swap(s[i], s[idx]);
        perm(idx + 1, n, s, ans);
        swap(s[i], s[idx]);  // Backtrack
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
    vector<string> ans;
    perm(0, s.size(), s, ans);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto v : ans) {
        cout << v << endl;
    }
}
