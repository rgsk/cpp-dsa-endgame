#include <bits/stdc++.h>

using namespace std;
namespace Solution {
int coverPoints(vector<int>& A, vector<int>& B);
}
int Solution::coverPoints(vector<int>& A, vector<int>& B) {
    int steps = 0;
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        steps += max(abs(A[i + 1] - A[i]), abs(B[i + 1] - B[i]));
    }
    return steps;
}

void test1() {
    vector<int> A = {0, 1, 1};
    vector<int> B = {0, 1, 2};
    int result = Solution::coverPoints(A, B);
    cout << result << endl;
}