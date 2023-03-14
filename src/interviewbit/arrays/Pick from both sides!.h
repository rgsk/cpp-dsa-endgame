#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();
    int sum = 0;
    for (int i = 0; i < B; i++) {
        sum += A[i];
    }
    int maxSum = sum;
    for (int i = B - 1; i >= 0; i--) {
        sum -= A[i];
        sum += A[n - B + i];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}
void test1() {
    vector<int> A = {5, -2, 3, 1, 2};
    int B = 3;
    int result = solve(A, B);
    cout << result << endl;
}
void test2() {
    vector<int> A = {1, 2};
    int B = 1;
    int result = solve(A, B);
    cout << result << endl;
}