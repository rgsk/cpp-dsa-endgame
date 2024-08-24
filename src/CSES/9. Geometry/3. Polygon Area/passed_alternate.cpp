#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<P> points(n);
    for (int i = 0; i < n; i++) {
        points[i].read();
    }
    ll area = 0;
    for (int i = 0; i < n; i++) {
        area += points[i] * points[(i + 1) % n];
    }
    cout << abs(area) << endl;
}
