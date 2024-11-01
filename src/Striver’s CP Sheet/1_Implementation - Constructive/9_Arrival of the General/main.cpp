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
        cin >> elems[i];
    }
    int max_index = 0;
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (elems[i] > elems[max_index]) {
            max_index = i;
        }
        if (elems[i] <= elems[min_index]) {
            min_index = i;
        }
    }
    cout << max_index + (n - min_index - (max_index < min_index ? 1 : 2)) << endl;
    return 0;
}