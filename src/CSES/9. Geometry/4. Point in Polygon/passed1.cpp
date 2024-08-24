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

bool intersect(P p1, P p2, P p3, P p4) {
    if ((p2 - p1) * (p4 - p3) == 0) {
        // two segments are parallel
        if (p1.triangle(p2, p3) != 0) {
            return false;
        }
        for (int rep = 0; rep < 2; rep++) {
            if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                return false;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        return true;
    }
    for (int rep = 0; rep < 2; rep++) {
        ll sign1 = (p2 - p1) * (p3 - p1);
        ll sign2 = (p2 - p1) * (p4 - p1);
        if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
            // segment B is on left or right from line A
            return false;  // no intersection
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    return true;
}

bool segment_contains(P& a, P& b, P& c) {
    if (a.triangle(b, c) != 0) {
        return false;  // not collinear
    }
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

/*
The provided solution uses the ray-casting algorithm to determine if a point lies inside a polygon.
This method checks how many times a ray, cast from the point in question to infinity, intersects the edges of the polygon.
If the count of intersections is odd, the point is inside the polygon; if even, it is outside.
 */
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<P> points(n);
    for (int i = 0; i < n; i++) {
        points[i].read();
    }
    for (int k = 0; k < m; k++) {
        P p;
        p.read();
        P out = {p.x + 1, 3'000'000'001LL};
        bool is_on_boundary = false;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (segment_contains(points[i], points[j], p)) {
                is_on_boundary = true;
                break;
            }
            if (intersect(points[i], points[j], p, out)) {
                count++;
            }
        }
        if (is_on_boundary) {
            cout << "BOUNDARY\n";
        } else {
            if (count % 2 == 0) {
                cout << "OUTSIDE\n";
            } else {
                cout << "INSIDE\n";
            }
        }
    }
}
