
#include <bits/stdc++.h>

#include "../../utils/utils.h"
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];
            }

            mp[sum]++;
        }
        return ans;
    }
};

class Solution2 {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        auto prefixes = prefixSum(nums);
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int s = prefixes[j] - prefixes[i];
                if (s == k) {
                    count += 1;
                }
            }
        }
        return count;
    }
};