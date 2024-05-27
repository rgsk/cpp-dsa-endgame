#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class SegmentTree {
   private:
    vector<ll> seg;
    vector<ll> lazy;
    int n;

    void build(const vector<int>& arr, int ind, int low, int high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(arr, 2 * ind + 1, low, mid);
        build(arr, 2 * ind + 2, mid + 1, high);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void rangeUpdate(int ind, int low, int high, int l, int r, int add) {
        if (lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // outside range
        if (high < l || low > r) {
            return;
        }
        // inside range
        if (low >= l && high <= r) {
            seg[ind] += (high - low + 1) * add;
            if (low != high) {
                lazy[2 * ind + 1] += add;
                lazy[2 * ind + 2] += add;
            }
            return;
        }

        int mid = (low + high) / 2;
        rangeUpdate(2 * ind + 1, low, mid, l, r, add);
        rangeUpdate(2 * ind + 2, mid + 1, high, l, r, add);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    ll queryLazy(int ind, int low, int high, int l, int r) {
        if (lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // inside range
        if (low >= l && high <= r) {
            return seg[ind];
        }

        // outside range
        if (high < l || low > r) {
            return 0;
        }

        int mid = (low + high) / 2;
        ll left = queryLazy(2 * ind + 1, low, mid, l, r);
        ll right = queryLazy(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

   public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        int nLevels = ceil(log2(n));
        int lengthOfSegmentTree = pow(2, nLevels + 1);
        seg.resize(lengthOfSegmentTree);
        lazy.resize(lengthOfSegmentTree);
        build(arr, 0, 0, n - 1);
    }

    ll findSumOfRange(int l, int r) {
        return queryLazy(0, 0, n - 1, l, r);
    }

    ll findValueAtIndex(int i) {
        return queryLazy(0, 0, n - 1, i, i);
    }

    void updateAtIndex(int i, int newVal) {
        // change value at index
        int add = newVal - findSumOfRange(i, i);
        rangeUpdate(0, 0, n - 1, i, i, add);
    }

    void updateIndexBy(int i, int add) {
        rangeUpdate(0, 0, n - 1, i, i, add);
    }

    void updateRangeInArr(int l, int r, int add) {
        rangeUpdate(0, 0, n - 1, l, r, add);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SegmentTree segmentTree(arr);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            segmentTree.updateRangeInArr(a - 1, b - 1, u);
        } else {
            int k;
            cin >> k;
            cout << segmentTree.findValueAtIndex(k - 1) << endl;
        }
    }
}
