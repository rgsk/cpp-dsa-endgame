#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            res.push_back(i * j);
        }
    }
    sort(res.begin(), res.end());
    int mid = res.size() / 2;
    cout << res[mid] << endl;
}