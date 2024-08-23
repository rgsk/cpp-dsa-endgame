#include <bits/stdc++.h>
using namespace std;
vector<int> prefixSum(vector<int>& vec) {
    int n = vec.size();
    vector<int> prefixes(n + 1);
    for (int i = 1; i <= n; i++) {
        prefixes[i] += vec[i - 1] + prefixes[i - 1];
    }
    return prefixes;
}
// get range sum using prefixSums
int rangeSum(vector<int>& prefixSums, int start, int end) {
    return prefixSums[end] - prefixSums[start];
}
int main() {
    vector<int> vec = {1, 2, 3, 4};

    vector<int> prefixSums = prefixSum(vec);

    // write some test cases
    assert(rangeSum(prefixSums, 0, 4) == 10);
    assert(rangeSum(prefixSums, 1, 3) == 5);
    assert(rangeSum(prefixSums, 2, 4) == 7);
    assert(rangeSum(prefixSums, 0, 2) == 3);
    cout << "success" << endl;
    return 0;
}
