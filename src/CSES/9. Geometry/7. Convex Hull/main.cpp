// video - https://youtu.be/G9QTjWtK_TQ?t=7804

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
    ll cross(const P& b) const {
        return 1LL * x * b.y - 1LL * y * b.x;
    }
    ll triangle(const P& b, const P& c) const {
        return (b - *this).cross(c - *this);
    }
    // implement less than operator for sorting
    bool operator<(const P& b) const {
        return make_pair(x, y) < make_pair(b.x, b.y);
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
    for (int i = 0; i < n; ++i) {
        points[i].read();
    }

    sort(points.begin(), points.end());  // Sort from left to right

    vector<P> hull;
    for (int rep = 0; rep < 2; ++rep) {
        const int S = hull.size();
        for (P C : points) {
            while ((int)hull.size() - S >= 2) {
                P A = hull.end()[-2];
                P B = hull.end()[-1];
                if (A.triangle(B, C) <= 0) {
                    break;  // B is on the left from C, good, don't do anything
                }
                hull.pop_back();  // Remove B
            }
            hull.push_back(C);
        }
        hull.pop_back();  // Remove rightmost point
        reverse(points.begin(), points.end());
    }

    cout << hull.size() << endl;
    for (P p : hull) {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}