#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first;
        vec[i].second = i + 1;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int total = vec[i].first + vec[l].first + vec[r].first;
            if (total == x) {
                cout << vec[i].second << " " << vec[l].second << " " << vec[r].second << endl;
                return 0;
            } else if (total < x) {
                l++;
            } else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
