#include <bits/stdc++.h>

#include "../../utils/utils.h"
using namespace std;

bool comp(const vector<int>& A,
          const vector<int>& B) {
    if (A[1] != B[1]) {
        return A[1] < B[1];
    }
    return A[0] < B[0];
}

int setIntersection(vector<vector<int>>& A) {
    int n = A.size();
    sort(A.begin(), A.end(), comp);
    vector<int> res;
    res.push_back(A[0][1] - 1);
    res.push_back(A[0][1]);
    for (int i = 1; i < n; i++) {
        int start = A[i][0];
        int end = A[i][1];
        int size = res.size();
        int last = res[size - 1];
        int secondLast = res[size - 2];
        if (start > last) {
            res.push_back(end - 1);
            res.push_back(end);
        } else if (start == last) {
            res.push_back(end);
        } else if (start > secondLast) {
            res.push_back(end);
        }
    }
    return res.size();
}

void test1() {
    vector<vector<int>> A = {
        {11, 14},
        {2, 10},
        {13, 15},
        {4, 6},
        {7, 20},
        {8, 20},
        {6, 12},
        {3, 19},
        {12, 14},
    };
    int result = setIntersection(A);
    print(A);
    cout << result << endl;
}
void test2() {
    vector<vector<int>> A = {{1, 2}, {2, 3}, {2, 4}, {4, 10}, {8, 9}, {9, 19}};
    int result = setIntersection(A);
    print(A);
    cout << result << endl;
}