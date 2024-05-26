#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<int> lengths(n);
    for (int i = 0; i < n; ++i) {
        cin >> lengths[i];
    }

    // Sort the lengths
    sort(lengths.begin(), lengths.end());

    // Calculate the median length
    int median;
    if (n % 2 == 0) {
        median = (lengths[n / 2 - 1] + lengths[n / 2]) / 2;
    } else {
        median = lengths[n / 2];
    }

    // Calculate the total cost
    long long total_cost = 0;
    for (int i = 0; i < n; ++i) {
        total_cost += abs(lengths[i] - median);
    }

    cout << total_cost << endl;

    return 0;
}