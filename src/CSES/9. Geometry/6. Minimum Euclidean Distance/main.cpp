// video - https://youtu.be/GDnSbn9A4Uk?t=5026

#include <bits/stdc++.h>
using namespace std;

struct P {
    int x, y;
    bool operator<(const P& b) const {
        return tie(y, x) < tie(b.y, b.x);
    }
    long long dist2(const P& b) const {
        return 1LL * (x - b.x) * (x - b.x) + 1LL * (y - b.y) * (y - b.y);
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
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), [&](const P& a, const P& b) {
        return a.x < b.x;
    });

    set<P> set;
    long long answer = 8e18 + 1e10;  // Large initial value for the minimum distance
    long long ans_sqrt = sqrt(answer);

    auto consider = [&](const P& a, const P& b) {
        long long d = a.dist2(b);
        if (d < answer) {
            answer = d;
            ans_sqrt = ceil(sqrt(answer));
        }
    };

    int i = 0;
    for (P p : points) {
        while (points[i].x < p.x - ans_sqrt) {
            set.erase(points[i]);
            i++;
        }

        auto it = set.lower_bound(p);
        auto memo_it = it;

        while (it != set.end() && it->y <= p.y + ans_sqrt) {
            consider(p, *it);
            ++it;
        }

        it = memo_it;
        while (it != set.begin()) {
            --it;
            if (it->y < p.y - ans_sqrt) {
                break;
            }
            consider(p, *it);
        }

        set.insert(p);
    }

    cout << answer << endl;
}