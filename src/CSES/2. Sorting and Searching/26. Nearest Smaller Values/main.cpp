#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    stack<pair<int, int>> st;
    st.push({0, 0});
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        while (st.top().first >= v) {
            st.pop();
        }
        cout << st.top().second << endl;
        st.push({v, i});
    }
}
