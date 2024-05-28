#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        auto it = st.upper_bound(v);
        if (it != st.end()) {
            st.erase(it);
            st.insert(v);
        } else {
            st.insert(v);
        }
    }
    cout << st.size() << endl;
}
