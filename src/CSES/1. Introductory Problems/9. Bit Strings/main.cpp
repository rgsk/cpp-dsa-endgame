#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * 2) % mod;
    }
    cout << ans << endl;
}
