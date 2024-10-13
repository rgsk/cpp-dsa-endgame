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
        int min_difference = INT_MAX;
        int prev = 0;
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            int current;
            cin >> current;
            if (current < prev) {
                sorted = false;
                break;
            }
            if (i > 0) {
                min_difference = min(min_difference, current - prev);
            }
            prev = current;
        }
        if (sorted) {
            cout << min_difference / 2 + 1 << endl;
        } else {
            cout << 0 << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}