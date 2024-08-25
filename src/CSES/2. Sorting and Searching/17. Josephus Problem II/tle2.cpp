#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;

    vector<int> children(n);
    iota(children.begin(), children.end(), 1);  // Fill the vector with 1 to n

    int index = 0;
    for (int i = 0; i < n; i++) {
        index = (index + k) % children.size();  // Find the index to remove
        cout << children[index] << " ";
        children.erase(children.begin() + index);
    }

    cout << endl;
    return 0;
}