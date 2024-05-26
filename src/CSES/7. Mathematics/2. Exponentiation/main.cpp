#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;

int exp(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        int res = exp(a, b / 2);
        res = (1LL * res * res) % mod;  // Apply mod after squaring
        if (b % 2 != 0) {
            res = (1LL * res * a) % mod;  // Apply mod after multiplication with 'a'
        }
        return res;
    }
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
    while (n > 0) {
        int a, b;
        cin >> a >> b;
        int res = exp(a, b);
        cout << res << endl;
        n--;
    }
}
