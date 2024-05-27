#include <cmath>
#include <iostream>
#include <vector>
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

ll findSumInRangeBruteForce(vector<int>& arr, int i, int j) {
    int idx = i;
    ll total = 0;
    while (idx <= j) {
        total += arr[idx];
        idx++;
    }
    return total;
}

int main() {
    // Input
    vector<int> arr = {8, 2, 5, 1, 4, 5, 3, 9, 6, 10};
    int n = arr.size();

    // Create Segment Tree
    SegmentTree segmentTree(arr);

    // Example query
    int result = segmentTree.findSumOfRange(3, 8);
    cout << result << endl;

    // Validate against brute force
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            SegmentTree bruteForce(arr);
            if (segmentTree.findSumOfRange(i, j) != findSumInRangeBruteForce(arr, i, j)) {
                cout << "MISMATCH" << endl;
            }
        }
    }
    int updateIdx = n - 2;
    int newValue = 9;
    arr[updateIdx] = newValue;
    segmentTree.updateAtIndex(updateIdx, newValue);

    // Validate against brute force
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            SegmentTree bruteForce(arr);
            if (segmentTree.findSumOfRange(i, j) != findSumInRangeBruteForce(arr, i, j)) {
                cout << "MISMATCH" << endl;
            }
        }
    }

    int startIdx = 1;
    int endIdx = 4;
    int add = 9;
    for (int i = startIdx; i <= endIdx; i++) {
        arr[i] += add;
    }
    segmentTree.updateRangeInArr(startIdx, endIdx, add);

    // Validate against brute force
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            SegmentTree bruteForce(arr);
            if (segmentTree.findSumOfRange(i, j) != findSumInRangeBruteForce(arr, i, j)) {
                cout << "MISMATCH" << endl;
            }
        }
    }

    return 0;
}
