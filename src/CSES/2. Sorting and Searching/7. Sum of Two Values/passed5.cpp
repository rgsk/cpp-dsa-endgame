#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<pair<int, int>>& a, int startIndex, int val) {
    int l = startIndex;
    int r = a.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m].first == val) {
            return a[m].second;
        } else if (a[m].first < val) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int cur = a[i].second;
        int other = binarySearch(a, i + 1, x - a[i].first);
        if (other != -1) {
            cout << cur + 1 << " " << other + 1 << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
