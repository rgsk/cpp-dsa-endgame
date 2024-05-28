#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    int ans = 0;
    multiset<int> st;
    for (int v : values) {
        auto it = st.upper_bound(v);
        if (it != st.end()) {
            st.erase(it);
            st.insert(v);
        } else {
            st.insert(v);
        }
        ans = max(ans, (int)st.size());
    }
    cout << ans << endl;
}
