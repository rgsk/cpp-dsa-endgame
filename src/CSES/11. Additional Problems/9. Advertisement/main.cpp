#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> min_prev(n, -1);
        vector<int> min_next(n, n);
        stack<int> st;

        // Finding previous smaller element for each bar
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                min_prev[i] = st.top();
            }
            st.push(i);
        }

        // Clear the stack to reuse it for the next smaller element
        while (!st.empty()) {
            st.pop();
        }

        // Finding next smaller element for each bar
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                min_next[i] = st.top();
            }
            st.push(i);
        }

        long long max_area = 0;

        // Calculate the maximum area
        for (int i = 0; i < n; i++) {
            max_area = max(max_area, 1LL * heights[i] * (min_next[i] - min_prev[i] - 1));
        }

        return max_area;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    Solution sol;
    cout << sol.largestRectangleArea(heights) << endl;
    return 0;
}