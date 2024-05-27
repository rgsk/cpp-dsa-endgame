#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegmentTree {
   private:
    vector<ll> seg;
    int n;

    void build(const vector<int>& arr, int ind, int low, int high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(arr, 2 * ind + 1, low, mid);
        build(arr, 2 * ind + 2, mid + 1, high);
        seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
    }

    ll query(int ind, int low, int high, int l, int r) {
        if (low >= l && high <= r) {
            return seg[ind];
        }
        if (high < l || low > r) {
            return 0;  // Adjust this based on your problem constraints
        }
        int mid = (low + high) / 2;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        return left ^ right;
    }

    void update(int ind, int low, int high, int i, int newVal) {
        if (low == high && low == i) {
            seg[ind] = newVal;
            return;
        }
        if (i < low || i > high) {
            return;
        }
        int mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, i, newVal);
        update(2 * ind + 2, mid + 1, high, i, newVal);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

   public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        int nLevels = ceil(log2(n));
        int lengthOfSegmentTree = pow(2, nLevels + 1);
        seg.resize(lengthOfSegmentTree);
        build(arr, 0, 0, n - 1);
    }

    ll findXorInRange(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    void updateAtIndex(int i, int newVal) {
        update(0, 0, n - 1, i, newVal);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    SegmentTree segmentTree(vec);

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << segmentTree.findXorInRange(a, b) << endl;
    }
}
