#include <bits/stdc++.h>
using namespace std;

void generate_subset_sums(int i, int total, vector<int>& t, vector<int>& subset_sums) {
    if (i == t.size()) {
        subset_sums.push_back(total);
        return;
    }
    // no take
    generate_subset_sums(i + 1, total, t, subset_sums);
    // take
    generate_subset_sums(i + 1, total + t[i], t, subset_sums);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    vector<int> subset_sums;
    generate_subset_sums(0, 0, t, subset_sums);

    int count = 0;
    for (int sum : subset_sums) {
        if (sum == x) {
            count++;
        }
    }
    cout << count << endl;
}
