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
        int n;
        cin >> n;
        int prev = 0;
        vector<int> values;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            if (v >= prev) {
                values.push_back(v);
            } else {
                values.push_back(v);
                values.push_back(v);
            }
            prev = v;
        }
        cout << values.size() << endl;
        for (int val : values) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}