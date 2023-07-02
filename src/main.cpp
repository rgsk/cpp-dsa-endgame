#include <bits/stdc++.h>

#include "utils/utils.h"
using namespace std;

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    auto res = maxSuffix(arr);
    print(res);
    return 0;
}

class Solution {
   public:
    vector<int> leaders(int a[], int n) {
        auto maxSuffixes = maxSuffix(a, n);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (a[i] == maxSuffixes[i]) {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};