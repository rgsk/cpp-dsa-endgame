#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
   private:
    std::vector<int> parent;
    std::vector<int> size;

   public:
    // Constructor to initialize the disjoint set with n elements
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find the representative (root) of the set to which the node belongs
    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        // Path compression: Update the parent of the node to the representative
        return parent[node] = findParent(parent[node]);
    }

    // Union by size
    void unionBySize(int node1, int node2) {
        int root1 = findParent(node1);
        int root2 = findParent(node2);
        if (root1 != root2) {
            if (size[root1] >= size[root2]) {
                parent[root2] = root1;
                size[root1] += size[root2];
            } else {
                parent[root1] = root2;
                size[root2] += size[root1];
            }
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    DisjointSet ds(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        ds.unionBySize(a, b);
    }
    vector<int> parents;
    for (int i = 1; i <= n; i++) {
        if (ds.findParent(i) == i) {
            parents.push_back(i);
        }
    }
    cout << parents.size() - 1 << endl;
    for (int i = 1; i < parents.size(); i++) {
        cout << parents[0] << " " << parents[i] << endl;
    }
}
