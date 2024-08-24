#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P {
    ll x, y;
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

// Pick's Theorem
// area = interior + boundary/2 - 1
// interior = area - boundary/2 + 1
// interior will always turn out to be integer, even if area and boundary/2 are not integers
// interior = 7.5 - 1.5 + 1 = 7

// interior = area - boundary/2 + 1
// 2 * interior = 2 * area - boundary + 2

// https://nrich.maths.org/problems/proof-picks-theorem

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<P> polygon(n);
    for (int i = 0; i < n; i++) {
        polygon[i].read();
    }
    ll twice_area = 0;
    for (int i = 0; i < n; i++) {
        twice_area += polygon[i] * polygon[(i + 1) % n];
    }
    twice_area = abs(twice_area);
    ll boundary_points = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        P diff = polygon[j] - polygon[i];
        ll gcd_val = gcd(abs(diff.x), abs(diff.y));
        boundary_points += gcd_val;
    }
    ll interior_points = (twice_area - boundary_points + 2) / 2;
    cout << interior_points << " " << boundary_points << endl;
    return 0;
}