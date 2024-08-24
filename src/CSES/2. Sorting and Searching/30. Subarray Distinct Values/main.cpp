#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    int left = 0, distinct_count = 0;
    long long total_subarrays = 0;

    for (int right = 0; right < n; right++) {
        // Add the current element to the window
        if (freq[arr[right]] == 0) {
            distinct_count++;
        }
        freq[arr[right]]++;

        // Shrink the window from the left if it has more than k distinct elements
        while (distinct_count > k) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0) {
                distinct_count--;
            }
            left++;
        }

        // Add the number of valid subarrays ending at `right`
        total_subarrays += (right - left + 1);
    }

    cout << total_subarrays << endl;

    return 0;
}