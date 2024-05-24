#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> g(n);
    for (int j = n - 1; j >= 0; j--) {
        cout << g[j];
    }
    cout << endl;
    for (int i = 1; i < (1 << n); i++) {
        int lsb = i & -i;
        int lsb_index = log2(lsb);
        g[lsb_index] ^= 1;
        for (int j = n - 1; j >= 0; j--) {
            cout << g[j];
        }
        cout << endl;
    }
}
