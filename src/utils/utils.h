#include "children/print.h"

template <typename T>
void reverse(T arr[], int start, int end) {
    end--;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

vector<int> prefixSum(vector<int> vec) {
    int n = vec.size();
    vector<int> prefixes(n + 1);
    for (int i = 1; i <= n; i++) {
        prefixes[i] += vec[i - 1] + prefixes[i - 1];
    }
    return prefixes;
}

vector<int> suffixSum(vector<int> vec) {
    int n = vec.size();
    vector<int> suffixes(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suffixes[i] += vec[i] + suffixes[i + 1];
    }
    return suffixes;
}
int sum(vector<int>::iterator begin, vector<int>::iterator end) {
    int ans = 0;
    while (begin < end) {
        ans += *begin;
        ++begin;  // Increment the iterator
    }
    return ans;
}
int sum(vector<int>& vec, int start, int end) {
    if (start > vec.size() || end > vec.size()) {
        cout << "Out of Index" << endl;
    }
    int total = 0;
    for (int i = start; i < end; i++) {
        total += vec[i];
    }
    return total;
}

int sum(int* arr, int start, int end) {
    int total = 0;
    for (int i = start; i < end; i++) {
        total += arr[i];
    }
    return total;
}

int index(vector<int>& arr, int value) {
    auto it = std::find(arr.begin(), arr.end(), value);
    if (it != arr.end()) {
        return distance(arr.begin(), it);
    }
    return -1;
}
int last_index(vector<int>& arr, int value) {
    auto it = std::find(arr.rbegin(), arr.rend(), value);
    if (it != arr.rend()) {
        return distance(it, arr.rend()) - 1;
    }
    return -1;
}