#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.push_back({v, i});
    }
    sort(a.begin(), a.end());
    int l = 0;
    int r = n - 1;
    while (l < r) {
        int total = a[l].first + a[r].first;
        if (total == x) {
            cout << a[l].second + 1 << " " << a[r].second + 1 << endl;
            return 0;
        } else {
            if (total > x) {
                r--;
            } else {
                l++;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
