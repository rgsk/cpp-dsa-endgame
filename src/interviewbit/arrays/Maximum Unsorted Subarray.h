#include <bits/stdc++.h>

#include "../../utils/utils.h"
using namespace std;

vector<int> subUnsort(vector<int> &A) {
    vector<int> ans;
    int n = A.size();
    int i = 0, j = n - 1;
    while (i < n - 1 and A[i] <= A[i + 1]) {
        i++;
    }
    while (j > 0 and A[j] >= A[j - 1]) {
        j--;
    }

    if (i == n - 1) {  // if array is already sorted, output -1
        ans.push_back(-1);
        return ans;
    }
    int mn = A[i + 1], mx = A[i + 1];
    // this is the crux and the optimization technique we use
    // rather than checking we min max for entire array
    // we ensure that we have got the max element from left and min element from right
    // and then see if there is element in left that is greater than min elem in distorted array
    // and if there is element on right that is less than max elem in distorted array

    // 0 1 2 3 4 5 6  7  8 9 10 11 12 13
    // 0 1 2 3 4 5 15 10 0 1  2  3  4  5
    // i = 6
    // j = 8
    for (int k = i; k <= j; k++) {
        mx = max(mx, A[k]);
        mn = min(mn, A[k]);
    }
    int l = 0, r = n - 1;
    while (A[l] <= mn and l <= i) {
        l++;
    }
    while (A[r] >= mx and r >= j) {
        r--;
    }
    ans.push_back(l);
    ans.push_back(r);
    return ans;
}
vector<int> subUnsortNaive(vector<int> &A) {
    vector<int> B = A;
    sort(B.begin(), B.end());
    int firstDifference = -1;
    int lastDifference = -1;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[i]) {
            if (firstDifference == -1) {
                firstDifference = i;
            } else {
                lastDifference = i;
            }
        }
    }
    vector<int> ans;
    if (firstDifference == -1) {
        ans = {-1};
    } else {
        ans = {firstDifference, lastDifference};
    }
    return ans;
}
vector<int> subUnsortNaive2(vector<int> &A) {
    int n = A.size();
    vector<int> minTracker(n);
    vector<int> maxTracker(n);
    maxTracker[0] = A[0];
    for (int i = 1; i < n; i++) {
        maxTracker[i] = max(maxTracker[i - 1], A[i]);
    }
    minTracker[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        minTracker[i] = min(minTracker[i + 1], A[i]);
    }
    int firstDifference = -1;
    int lastDifference = -1;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != minTracker[i] || A[i] != maxTracker[i]) {
            if (firstDifference == -1) {
                firstDifference = i;
            } else {
                lastDifference = i;
            }
        }
    }
    vector<int> ans;
    if (firstDifference == -1) {
        ans = {-1};
    } else {
        ans = {firstDifference, lastDifference};
    }
    return ans;
}
void test1() {
    vector<int> A = {
        0,
        1,
        2,
        3,
        4,
        5,
        15,
        10,
        0,
        1,
        2,
        3,
        4,
        5,
    };
    print(A);
    auto res = subUnsortNaive2(A);
    print(res);
}