#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    long long sum = 0;
    long long max_value = 0;
    for (int i = 0; i < n; ++i) {
        long long v;
        cin >> v;
        max_value = max(max_value, v);
        sum += v;
    }
    cout << max(sum, max_value * 2) << endl;
    return 0;
}
