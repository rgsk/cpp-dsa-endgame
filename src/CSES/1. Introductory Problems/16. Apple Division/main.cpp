#include <bits/stdc++.h>
using namespace std;

long long solve(int i, long long s1, long long s2, vector<int>& arr, int n) {
    if (i == n) {
        return abs(s1 - s2);
    }
    return min(solve(i + 1, s1 + arr[i], s2, arr, n), solve(i + 1, s1, s2 + arr[i], arr, n));
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int ans = solve(0, 0, 0, vec, n);
    cout << ans << endl;
}
