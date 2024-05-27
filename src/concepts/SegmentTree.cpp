#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
   private:
    vector<int> seg;
    int n;

    void build(const vector<int>& arr, int ind, int low, int high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(arr, 2 * ind + 1, low, mid);
        build(arr, 2 * ind + 2, mid + 1, high);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        if (low >= l && high <= r) {
            return seg[ind];
        }
        if (high < l || low > r) {
            return INT_MIN;  // Adjust this based on your problem constraints
        }
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return max(left, right);
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
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

   public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        int nLevels = ceil(log2(n));
        int lengthOfSegmentTree = pow(2, nLevels + 1);
        seg.resize(lengthOfSegmentTree);
        build(arr, 0, 0, n - 1);
    }

    int findMaxInRange(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    void updateAtIndex(int i, int newVal) {
        update(0, 0, n - 1, i, newVal);
    }
};

int findMaxInRangeBruteForce(vector<int>& arr, int i, int j) {
    int idx = i;
    int max_value = arr[idx];
    while (idx <= j) {
        max_value = max(arr[idx], max_value);
        idx++;
    }
    return max_value;
}

int main() {
    // Input
    vector<int> arr = {8, 2, 5, 1, 4, 5, 3, 9, 6, 10};
    int n = arr.size();

    // Create Segment Tree
    SegmentTree segmentTree(arr);

    // Example query
    int result = segmentTree.findMaxInRange(3, 8);
    cout << result << endl;

    // Validate against brute force
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            SegmentTree bruteForce(arr);
            if (segmentTree.findMaxInRange(i, j) != findMaxInRangeBruteForce(arr, i, j)) {
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
            if (segmentTree.findMaxInRange(i, j) != findMaxInRangeBruteForce(arr, i, j)) {
                cout << "MISMATCH" << endl;
            }
        }
    }

    return 0;
}
