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
    ll cross(const P& b) const {
        return x * b.y - y * b.x;
    }
};

int winding_number(vector<P>& polygon, P& p) {
    int wn = 0;  // winding number counter

    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        P p1 = polygon[i];
        P p2 = polygon[(i + 1) % n];

        if (p1.y <= p.y) {
            if (p2.y > p.y) {  // upward crossing
                if ((p2 - p1).cross(p - p1) > 0) {
                    wn++;
                }
            }
        } else {
            if (p2.y <= p.y) {  // downward crossing
                if ((p2 - p1).cross(p - p1) < 0) {
                    wn--;
                }
            }
        }
    }
    return wn;
}

bool segment_contains(P& a, P& b, P& c) {
    ll cross = (b - a).cross(c - a);
    if (cross != 0) {
        return false;  // not collinear
    }
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

// Winding Number Algorithm

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

        bool is_on_boundary = false;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (segment_contains(points[i], points[j], p)) {
                is_on_boundary = true;
                break;
            }
        }

        if (is_on_boundary) {
            cout << "BOUNDARY\n";
        } else {
            int wn = winding_number(points, p);
            if (wn == 0) {
                cout << "OUTSIDE\n";
            } else {
                cout << "INSIDE\n";
            }
        }
    }
}