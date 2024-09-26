#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        int count = 0;
        for (int i = 1; i <= sqrt(x); i++) {
            if (x % i == 0) {
                if (i == x / i) {
                    count++;
                } else {
                    count += 2;
                }
            }
        }
        cout << count << endl;
    }
}
