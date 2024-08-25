#include <bits/stdc++.h>
using namespace std;
// Function to calculate the Hamming distance between two strings
int hammingDistance(const string &a, const string &b) {
    int dist = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            dist++;
        }
    }
    return dist;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Iterate over all pairs of strings and calculate the Hamming distance
    int minHamming = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            minHamming = min(minHamming, hammingDistance(a[i], a[j]));
        }
    }
    cout << minHamming << endl;
}