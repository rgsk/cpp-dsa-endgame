#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to divide the array into k subarrays
// such that the sum of each subarray does not exceed the maxSum
bool isPossible(const vector<int>& nums, int k, long long maxSum) {
    int count = 1;
    long long currentSum = 0;
    for (int num : nums) {
        currentSum += num;
        if (currentSum > maxSum) {
            count++;
            currentSum = num;
        }
    }
    return count <= k;
}

// Function to find the smallest possible maximum sum in a subarray
long long smallestMaxSum(const vector<int>& nums, int k) {
    long long left = *max_element(nums.begin(), nums.end());  // Minimum possible sum
    long long right = 0;
    for (int v : nums) {
        right += v;
    }
    long long result = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (isPossible(nums, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << smallestMaxSum(nums, k) << endl;
    return 0;
}
