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
        return (b - *this) * (c - *this);
    }
};

void test_case() {
    P p1, p2, p3, p4;
    p1.read();
    p2.read();
    p3.read();
    p4.read();
    if ((p2 - p1) * (p4 - p3) == 0) {
        // two segments are parallel
        if (p1.triangle(p2, p3) != 0) {
            cout << "NO\n";
            return;
        }
        for (int rep = 0; rep < 2; rep++) {
            if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                cout << "NO\n";
                return;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
    }
    for (int rep = 0; rep < 2; rep++) {
        ll sign1 = (p2 - p1) * (p3 - p1);
        ll sign2 = (p2 - p1) * (p4 - p1);
        if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
            // segment B is on left or right from line A
            cout << "NO" << endl;  // no intersection
            return;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    cout << "YES" << endl;
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
