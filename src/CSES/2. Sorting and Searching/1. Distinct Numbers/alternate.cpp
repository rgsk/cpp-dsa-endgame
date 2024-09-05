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
    sort(arr.begin(), arr.end());
    int cur = arr[0];
    int diff_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != cur) {
            diff_count += 1;
            cur = arr[i];
        }
    }
    cout << diff_count << endl;
    return 0;
}