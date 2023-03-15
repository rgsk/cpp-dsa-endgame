#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &vec, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    vector<int> temp(end - start + 1);
    int k = 0;
    while (i <= mid && j <= end) {
        if (vec[i] < vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = vec[i++];
    }
    while (j <= end) {
        temp[k++] = vec[j++];
    }
    k = 0;
    for (int i = start; i <= end; i++) {
        vec[i] = temp[k++];
    }
}

void merge_sort(vector<int> &vec, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(vec, start, mid);
        merge_sort(vec, mid + 1, end);
        merge(vec, start, mid, end);
    }
}

void merge_sort(vector<int> &vec) {
    int start = 0;
    int end = vec.size() - 1;
    merge_sort(vec, start, end);
}
