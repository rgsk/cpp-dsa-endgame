#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int v;
            cin >> v;
            if (v == 1) {
                // we can determine the answer
                cout << abs(i - 3) + abs(j - 3) << endl;
                return 0;
            }
        }
    }
}