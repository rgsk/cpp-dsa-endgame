#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int> &vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && vec[j] < vec[j - 1]) {
            swap(vec[j], vec[j - 1]);
            j--;
        }
    }
}
