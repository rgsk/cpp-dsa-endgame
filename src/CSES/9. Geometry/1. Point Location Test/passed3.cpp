#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// https://www.youtube.com/watch?v=G9QTjWtK_TQ
struct P {
    ll x, y;
    void read() {
        cin >> x >> y;
    }
    P operator-(const P& b) const {
        return P{x - b.x, y - b.y};
    }
    ll cross(const P& b) const {
        return x * b.y - y * b.x;
    }
};

void test_case() {
    P p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();
    ll cross_product = (p2 - p1).cross(p3 - p1);
    // refer corss_prod.png
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
