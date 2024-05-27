#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    multiset<int> maxHeap;
    multiset<int> minHeap;
    for (int i = 0; i < k; i++) {
        maxHeap.insert(arr[i]);
    }

    auto erase = [&](int v) {
        if (v >= *minHeap.begin()) {
            minHeap.erase(minHeap.find(v));
        } else {
            maxHeap.erase(maxHeap.find(v));
        }
    };
    auto balance = [&]() {
        while (maxHeap.size() >= minHeap.size()) {
            int v = *maxHeap.rbegin();
            minHeap.insert(v);
            maxHeap.erase(maxHeap.find(v));
        }
        while (minHeap.size() > maxHeap.size() + 2) {
            int v = *minHeap.begin();
            maxHeap.insert(v);
            minHeap.erase(minHeap.find(v));
        }
    };
    balance();

    cout << *minHeap.begin() << " ";
    for (int i = k; i < n; i++) {
        if (arr[i] >= *minHeap.begin()) {
            minHeap.insert(arr[i]);
        } else {
            maxHeap.insert(arr[i]);
        }
        erase(arr[i - k]);
        balance();
        cout << *minHeap.begin() << " ";
    }
    cout << endl;
}
