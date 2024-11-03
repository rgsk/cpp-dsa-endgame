#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int limak, bob;
    cin >> limak >> bob;
    int ans = 0;
    while (limak <= bob) {
        limak *= 3;
        bob *= 2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}