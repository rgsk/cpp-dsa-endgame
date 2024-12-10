#include <bits/stdc++.h>

using namespace std;

void count_sort(vector<int> &vec) {
    int n = vec.size();
    if (n == 0) {
        return;
    }
    int max_element = vec[0];
    for (int i = 1; i < n; i++) {
        if (vec[i] > max_element) {
            max_element = vec[i];
        }
    }
    vector<int> freq(max_element + 1);
    for (int v : vec) {
        freq[v]++;
    }
    int i = 0;
    int idx = 0;
    while (i <= max_element) {
        while (freq[i] > 0) {
            vec[idx] = i;
            freq[i]--;
            idx++;
        }
        i++;
    }
}
