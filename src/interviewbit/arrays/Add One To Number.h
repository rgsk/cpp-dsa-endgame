#include <bits/stdc++.h>

#include "../../utils/utils.h"
using namespace std;
vector<int> plusOne(vector<int> &A) {
    int n = A.size();
    bool rem = false;
    int i = n - 1;
    for (; i >= 0; i--) {
        if (A[i] + 1 == 10) {
            A[i] = 0;
            rem = true;
        } else {
            A[i]++;
            rem = false;
            break;
        }
    }
    if (rem) {
        if (i >= 0) {
            A[i]++;
        } else {
            A.insert(A.begin(), 1);
        }
    }
    i = 0;
    while (i < A.size() && A[i] == 0) {
        i++;
    }
    A.erase(A.begin(), A.begin() + i);
    return A;
}

void test1() {
    vector<int> vec = {9, 9, 9};
    auto ans = plusOne(vec);
    print(ans);
}
void test2() {
    vector<int> vec = {0, 3, 7, 6, 4, 0, 5, 5, 5};
    auto ans = plusOne(vec);
    print(ans);
}