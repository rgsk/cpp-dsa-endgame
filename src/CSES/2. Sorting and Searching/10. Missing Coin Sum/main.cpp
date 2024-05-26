#include <bits/stdc++.h>
using namespace std;

long long smallestUncreatedSum(vector<int>& coins) {
    sort(coins.begin(), coins.end());
    long long running_sum = 0;
    for (int coin : coins) {
        if (running_sum + 1 < coin) {
            return running_sum + 1;
        }
        running_sum += coin;
    }
    return running_sum + 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    cout << smallestUncreatedSum(vec) << endl;
}
