#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> elems(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        elems[v - 1] = i + 1;
    }
    for (int v : elems) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}