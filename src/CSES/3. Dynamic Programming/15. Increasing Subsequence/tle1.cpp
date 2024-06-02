#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(const vector<int>& nums) {
    int n = nums.size();
    vector<long long> dp(n, 1);  // Initialize dp array with all values as 1

    // Iterate over all indices i from 1 to n-1
    for (int i = 1; i < n; ++i) {
        // Iterate over all indices j from 0 to i-1
        for (int j = 0; j < i; ++j) {
            // If nums[j] < nums[i], update dp[i] to be the maximum value of dp[j] + 1
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum value in dp array
    long long max_length = 0;
    for (int i = 0; i < n; ++i) {
        max_length = max(max_length, dp[i]);
    }

    return max_length;
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
