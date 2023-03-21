#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int> &vec) {
    int len = vec.size();
    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        swap(vec[minIndex], vec[i]);
    }
}
