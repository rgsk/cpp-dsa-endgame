#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maximumProduct(vector<int>& nums) {
        // we need to return product of largest 3 numbers in the array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};

int main() {
}