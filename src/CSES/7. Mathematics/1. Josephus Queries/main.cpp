// video - https://www.youtube.com/watch?v=lIr78Tj1qww

#include <bits/stdc++.h>
using namespace std;

int find(int n, int k) {
    if (n == 1) {
        return 1;
    }
    if (k <= (n + 1) / 2) {
        if (2 * k > n) {
            return 2 * k - n;
        }
        return 2 * k;
    }
    int x = find(n / 2, k - (n + 1) / 2);
    if (n % 2 == 0) {
        return 2 * x - 1;
    }
    return 2 * x + 1;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << find(n, k) << endl;
    }
    return 0;
}
