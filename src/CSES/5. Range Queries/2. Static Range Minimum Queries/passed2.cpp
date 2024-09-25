#include <bits/stdc++.h>
using namespace std;

class SparseTable {
   public:
    vector<vector<int>> table;

    SparseTable(const vector<int>& data) {
        int n = data.size();
        int max_log = log2(n) + 1;
        table.resize(n, vector<int>(max_log));

        // Build the sparse table
        for (int i = 0; i < n; i++) {
            table[i][0] = data[i];
        }

        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int log = log2(r - l + 1);
        return min(table[l][log], table[r - (1 << log) + 1][log]);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    SparseTable st(nums);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << st.query(a - 1, b - 1) << endl;  // Convert 1-based index to 0-based
    }

    return 0;
}