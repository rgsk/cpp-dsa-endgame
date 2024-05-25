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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto original = a;
    sort(a.begin(), a.end());
    int l = 0;
    int r = n - 1;
    while (l < r) {
        int total = a[l] + a[r];
        if (total == x) {
            if (a[l] == a[r]) {
                int li = find(original.begin(), original.end(), a[l]) - original.begin();
                int ri = find(original.begin() + li + 1, original.end(), a[r]) - original.begin();
                cout << li + 1 << " " << ri + 1 << endl;
            } else {
                int li = find(original.begin(), original.end(), a[l]) - original.begin();
                int ri = find(original.begin(), original.end(), a[r]) - original.begin();
                cout << li + 1 << " " << ri + 1 << endl;
            }
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
