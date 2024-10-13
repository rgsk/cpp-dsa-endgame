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
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int largest = arr[arr.size() - 1];
        int largest_count = arr.end() - lower_bound(arr.begin(), arr.end(), largest);
        if (largest_count == n) {
            cout << -1 << endl;
            continue;
        }
        cout << n - largest_count << " " << largest_count << endl;
        int i = 0;
        while (arr[i] != largest) {
            cout << arr[i] << ' ';
            i++;
        }
        cout << endl;
        while (i < n) {
            cout << arr[i] << ' ';
            i++;
        }
        cout << endl;
    }
    return 0;
}