#include <bits/stdc++.h>
using namespace std;
vector<int> prefixXor(vector<int>& vec) {
    int n = vec.size();
    vector<int> prefixes(n + 1);
    for (int i = 1; i <= n; i++) {
        prefixes[i] = vec[i - 1] ^ prefixes[i - 1];
    }
    return prefixes;
}
// get range sum using prefixXors
int rangeXor(vector<int>& prefixXors, int start, int end) {
    return prefixXors[end] ^ prefixXors[start];
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    long long n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    vector<int> prefixXors = prefixXor(vec);
    // get the maximum subarray xor
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans = max(ans, rangeXor(prefixXors, i, j));
        }
    }
    cout << ans << endl;
}
