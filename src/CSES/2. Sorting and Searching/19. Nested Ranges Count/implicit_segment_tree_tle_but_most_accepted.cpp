#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class ImplicitSegmentTree {
   private:
    struct Node {
        ll value = 0;
        ll lazy = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root;
    int start, end;

    void applyLazy(Node* node, int l, int r) {
        if (node->lazy != 0) {
            node->value += (r - l + 1) * node->lazy;
            if (l != r) {
                if (!node->left) node->left = new Node();
                if (!node->right) node->right = new Node();
                node->left->lazy += node->lazy;
                node->right->lazy += node->lazy;
            }
            node->lazy = 0;
        }
    }

    void rangeUpdate(Node* node, int l, int r, int u, int v, ll add) {
        if (l > v || r < u) return;

        if (l >= u && r <= v) {
            node->lazy += add;
            applyLazy(node, l, r);
            return;
        }

        int mid = (l + r) / 2;
        if (!node->left) node->left = new Node();
        if (!node->right) node->right = new Node();
        rangeUpdate(node->left, l, mid, u, v, add);
        rangeUpdate(node->right, mid + 1, r, u, v, add);
        node->value = node->left->value + node->right->value;
    }

    ll queryRange(Node* node, int l, int r, int u, int v) {
        if (!node || l > v || r < u) return 0;

        applyLazy(node, l, r);

        if (l >= u && r <= v) return node->value;

        int mid = (l + r) / 2;
        return queryRange(node->left, l, mid, u, v) + queryRange(node->right, mid + 1, r, u, v);
    }

   public:
    ImplicitSegmentTree(int s, int e) : start(s), end(e) {
        root = new Node();
    }

    void update(int u, int v, ll add) {
        rangeUpdate(root, start, end, u, v, add);
    }

    ll query(int u, int v) {
        return queryRange(root, start, end, u, v);
    }

    void resetTree(Node* node) {
        if (!node) return;
        node->value = 0;
        node->lazy = 0;
        resetTree(node->left);
        resetTree(node->right);
    }

    // write a reset function that sets each value
    // in the segment tree to 0
    void reset() {
        resetTree(this->root);
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
    int maxEnd = 0;
    int minStart = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].start >> ranges[i].end;
        maxEnd = max(maxEnd, ranges[i].end);
        minStart = min(minStart, ranges[i].start);
        ranges[i].index = i;
    }

    // Sort ranges by starting point, and by descending end point for the same start point
    sort(ranges.begin(), ranges.end(), compare);

    // use segment tree
    ImplicitSegmentTree segmentTree(minStart, maxEnd);

    // calculate isContainedBy
    for (int i = 0; i < n; i++) {
        isContainedBy[ranges[i].index] = segmentTree.query(ranges[i].end, maxEnd);
        segmentTree.update(ranges[i].end, ranges[i].end, 1);
    }

    // reset segment tree
    segmentTree.reset();

    // calculate contains
    for (int i = n - 1; i >= 0; i--) {
        contains[ranges[i].index] = segmentTree.query(ranges[i].start, ranges[i].end);
        segmentTree.update(ranges[i].end, ranges[i].end, 1);
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