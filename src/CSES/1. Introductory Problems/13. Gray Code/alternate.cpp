#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> g(n);

    // Initial output of g
    for (int j = n - 1; j >= 0; j--) {
        cout << g[j];
    }
    cout << endl;

    for (int i = 1; i < (1 << n); i++) {
        // Get the index of the least significant set bit using __builtin_ctz
        int lsb_index = __builtin_ctz(i);
        g[lsb_index] ^= 1;

        // Print the current Gray code representation
        for (int j = n - 1; j >= 0; j--) {
            cout << g[j];
        }
        cout << endl;
    }
}