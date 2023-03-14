#include <bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int> &vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j + 1] < vec[j]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}
