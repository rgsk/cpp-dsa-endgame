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
        applyLazy(node, l, r);

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
};

int main() {
    int n = 10;
    int start = 1, end = 1000000000;  // Example range

    ImplicitSegmentTree segTree(start, end);

    // Example updates
    segTree.update(1, 10, 5);
    segTree.update(20, 30, 10);
    segTree.update(15, 25, 3);

    // Example queries
    cout << segTree.query(1, 10) << endl;   // Output the sum in range [1, 10]
    cout << segTree.query(15, 20) << endl;  // Output the sum in range [15, 20]
    cout << segTree.query(1, 30) << endl;   // Output the sum in range [1, 30]

    return 0;
}