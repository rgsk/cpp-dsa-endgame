#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 5;
    vector<int> children(n);
    iota(children.begin(), children.end(), 1);  // Fill the vector with 1 to n
    // print children
    for (int i = 0; i < n; i++) {
        cout << children[i] << " ";
    }
}
