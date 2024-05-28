#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<int> st;
    int i = 0;
    int j = 0;
    int max_length = 0;
    while (j < n) {
        while (st.find(arr[j]) != st.end()) {
            st.erase(arr[i]);
            i += 1;
        }
        st.insert(arr[j]);
        max_length = max(max_length, j - i + 1);
        j += 1;
    }
    cout << max_length << endl;
}
