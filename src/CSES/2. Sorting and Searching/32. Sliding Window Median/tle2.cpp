#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<pair<int, int>> st;
    for (int i = 0; i < k; i++) {
        st.insert({arr[i], i});
    }
    int idx = (k - 1) / 2;
    auto mid = next(st.begin(), idx);
    cout << mid->first << " ";
    for (int i = k; i < n; i++) {
        st.erase({arr[i - k], i - k});
        st.insert({arr[i], i});
        auto mid = next(st.begin(), idx);
        cout << mid->first << " ";
    }
    cout << endl;
}
