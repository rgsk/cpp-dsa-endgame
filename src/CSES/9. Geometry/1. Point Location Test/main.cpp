#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// https://www.youtube.com/watch?v=G9QTjWtK_TQ
struct P {
    int x, y;
    void read() {
        cin >> x >> y;
    }
    P operator-(const P& b) const {
        return P{x - b.x, y - b.y};
    }
    void operator-=(const P& b) {
        x -= b.x;
        y -= b.y;
    }
    ll operator*(const P& b) const {
        return 1LL * x * b.y - 1LL * y * b.x;
    }
    ll triangle(const P& b, const P& c) const {
        // returns value < 0 if b is on left of c
        // when looking from this to b
        return (b - *this) * (c - *this);
    }
};

void test_case() {
    P p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();
    ll cross_product = p1.triangle(p2, p3);
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
