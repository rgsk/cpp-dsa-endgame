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
    SegmentTree(int size) {
        this->n = size;
        int nLevels = ceil(log2(n));
        int lengthOfSegmentTree = pow(2, nLevels + 1);
        seg.resize(lengthOfSegmentTree);
        lazy.resize(lengthOfSegmentTree);
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

    void reset() {
        fill(seg.begin(), seg.end(), 0);
        fill(lazy.begin(), lazy.end(), 0);
    }
};

struct Range {
    int start, end, index;
};
bool compare(const Range& a, const Range& b) {
    if (a.start == b.start)
        return a.end > b.end;  // Sort by end descending if start is the same
    return a.start < b.start;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<Range> ranges(n);
    vector<int> contains(n, 0);
    vector<int> isContainedBy(n, 0);
    set<int> coordSet;

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].index = i;
        coordSet.insert(ranges[i].start);
        coordSet.insert(ranges[i].end);
    }

    // Coordinate compression
    unordered_map<int, int> coordMap;
    int maxEnd = 0;
    for (int coord : coordSet) {
        coordMap[coord] = maxEnd++;
    }

    // Adjust ranges with compressed coordinates
    for (int i = 0; i < n; i++) {
        ranges[i].start = coordMap[ranges[i].start];
        ranges[i].end = coordMap[ranges[i].end];
    }

    // Sort ranges by starting point, and by descending end point for the same start point
    sort(ranges.begin(), ranges.end(), compare);

    // use segment tree
    SegmentTree segmentTree(maxEnd);

    // calculate isContainedBy
    for (int i = 0; i < n; i++) {
        isContainedBy[ranges[i].index] = segmentTree.findSumOfRange(ranges[i].end, maxEnd - 1);
        segmentTree.updateIndexBy(ranges[i].end, 1);
    }

    // reset segment tree
    segmentTree.reset();

    // calculate contains
    for (int i = n - 1; i >= 0; i--) {
        contains[ranges[i].index] = segmentTree.findSumOfRange(ranges[i].start, ranges[i].end);
        segmentTree.updateIndexBy(ranges[i].end, 1);
    }

    // Output the results
    for (int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << isContainedBy[i] << " ";
    }
    cout << endl;
    return 0;
}