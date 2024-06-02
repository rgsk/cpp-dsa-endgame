#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void test_case() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    x2 -= x1;
    y2 -= y1;
    x3 -= x1;
    y3 -= y1;
    ll cross_product = 1LL * x2 * y3 - 1LL * x3 * y2;
    if (cross_product < 0) {
        cout << "RIGHT" << endl;
    } else if (cross_product > 0) {
        cout << "LEFT" << endl;
    } else {
        cout << "TOUCH" << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
}
