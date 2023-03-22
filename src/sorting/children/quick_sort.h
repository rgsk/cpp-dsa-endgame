#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &vec, int start, int end) {
    int pivot = vec[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[end]);
    return i + 1;
}

void quick_sort(vector<int> &vec, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(vec, start, end);
        quick_sort(vec, start, pivotIndex - 1);
        quick_sort(vec, pivotIndex + 1, end);
    }
}
void quick_sort(vector<int> &vec) {
    int start = 0;
    int end = vec.size() - 1;
    quick_sort(vec, start, end);
}
