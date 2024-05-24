#include <bits/stdc++.h>
using namespace std;

long long solve(long long n) {
    return ((n * n) * ((n * n) - 1)) / 2 - 4 * (n - 1) * (n - 2);
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << solve(i) << endl;
    }
}
