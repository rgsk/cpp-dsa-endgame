#include <bits/stdc++.h>
using namespace std;

vector<int> generateSubsetSums(vector<int>& arr) {
    vector<int> ans = {0};
    for (int v : arr) {
        int len = ans.size();
        for (int i = 0; i < len; i++) {
            ans.push_back(ans[i] + v);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3};
    auto subsets = generateSubsetSums(arr);
    for (int v : subsets) {
        cout << v << " ";
    }
    cout << endl;
    // 0 1 2 3 3 4 5 6
}
