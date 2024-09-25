#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        // we need to find the first i where citations[i] >= n - i;
        // and return n - i
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (citations[m] >= n - m) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return n - r;
    }
};