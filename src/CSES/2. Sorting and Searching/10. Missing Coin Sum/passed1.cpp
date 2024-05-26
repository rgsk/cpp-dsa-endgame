#include <bits/stdc++.h>
using namespace std;

/*
This approach exploits the fact that,
if smallest_sum is smaller than the current coin value,
 we cannot create smallest_sum using any subset of the coins seen so far.
  Hence, we return smallest_sum. Otherwise,
   we update smallest_sum to include the current coin value,
    as it can be used to create sums up to smallest_sum + coin - 1.
*/

long long smallestUncreatedSum(vector<int>& coins) {
    sort(coins.begin(), coins.end());  // Sort the coins in ascending order

    long long smallest_sum = 1;  // Initialize the smallest sum

    for (int coin : coins) {
        // If coin > smallest_sum, then smallest_sum cannot be created using any subset of coins
        if (coin > smallest_sum) {
            return smallest_sum;
        }
        // Otherwise, update smallest_sum to include the current coin value
        smallest_sum += coin;
    }

    return smallest_sum;
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
