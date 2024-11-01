
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> elems(3);
    for (int i = 0; i < 3; i++) {
        cin >> elems[i];
    }
    sort(elems.begin(), elems.end());
    cout << elems[1] - elems[0] + elems[2] - elems[1] << endl;
    return 0;
}