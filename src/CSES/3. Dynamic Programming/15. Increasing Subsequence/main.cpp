#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(const vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);

    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
        *it = nums[i];
    }

    return lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << longestIncreasingSubsequence(nums) << endl;
    return 0;
}
