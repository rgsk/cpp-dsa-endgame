#include <bits/stdc++.h>
using namespace std;
int sumUpto(int n) {
    return (n * (n + 1)) / 2;
}
class Solution {
   public:
    int maximizeSum(vector<int>& nums, int k) {
        int max_value = *max_element(nums.begin(), nums.end());
        int total = 0;
        int sumUpToMaxValue = sumUpto(max_value - 1);
        int sumUpToMaxPlusK = sumUpto(max_value + k - 1);
        return sumUpToMaxPlusK - sumUpToMaxValue;
    }
};

int main() {
    vector<int> nums = {5, 5, 5};
    int k = 2;
    Solution sol;
    cout << sol.maximizeSum(nums, k) << endl;
}
