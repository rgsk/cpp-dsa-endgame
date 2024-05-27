#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
   private:
    vector<int> seg;

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

   public:
    SegmentTree(const vector<int>& arr, int n) {
        int nLevels = ceil(log2(n));
        int lengthOfSegmentTree = pow(2, nLevels + 1);
        seg.resize(lengthOfSegmentTree);
        build(arr, 0, 0, n - 1);
    }

    int findMaxInRange(int l, int r, int n) {
        return query(0, 0, n - 1, l, r);
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
    SegmentTree segmentTree(arr, n);

    // Example query
    int result = segmentTree.findMaxInRange(3, 8, n);
    cout << result << endl;

    // Validate against brute force
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            SegmentTree bruteForce(arr, n);
            if (segmentTree.findMaxInRange(i, j, n) != findMaxInRangeBruteForce(arr, i, j)) {
                cout << "MISMATCH" << endl;
            }
        }
    }

    return 0;
}
