#include <bits/stdc++.h>

#include "../../utils/utils.h"
using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 4) {
            return {};
        }
        vector<vector<int>> answer;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int low = j + 1, high = nums.size() - 1;
                long long sum = 0;
                while (low < high) {
                    sum = nums[i] + nums[j];
                    sum += nums[low] + nums[high];
                    if (sum > target) {
                        high--;
                    } else if (sum < target) {
                        low++;
                    } else {
                        answer.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int last_low_occurence = nums[low], last_high_occurence = nums[high];
                        while (low < high && nums[low] == last_low_occurence) {
                            low++;
                        }
                        while (low < high && nums[high] == last_high_occurence) {
                            high--;
                        }
                    }
                }
            }
        }
        return answer;
    }
};