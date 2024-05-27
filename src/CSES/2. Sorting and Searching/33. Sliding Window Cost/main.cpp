#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll minHeapSum = 0;
    ll maxHeapSum = 0;

    for (int i = 0; i < k; i++) {
        maxHeap.insert(arr[i]);
        maxHeapSum += arr[i];
    }

    auto erase = [&](int v) {
        if (v >= *minHeap.begin()) {
            minHeap.erase(minHeap.find(v));
            minHeapSum -= v;
        } else {
            maxHeap.erase(maxHeap.find(v));
            maxHeapSum -= v;
        }
    };
    auto balance = [&]() {
        while (maxHeap.size() >= minHeap.size()) {
            int v = *maxHeap.rbegin();
            minHeap.insert(v);
            maxHeap.erase(maxHeap.find(v));
            minHeapSum += v;
            maxHeapSum -= v;
        }
        while (minHeap.size() > maxHeap.size() + 2) {
            int v = *minHeap.begin();
            maxHeap.insert(v);
            minHeap.erase(minHeap.find(v));
            maxHeapSum += v;
            minHeapSum -= v;
        }
    };
    auto insert = [&](int v) {
        if (v >= *minHeap.begin()) {
            minHeap.insert(v);
            minHeapSum += v;
        } else {
            maxHeap.insert(v);
            maxHeapSum += v;
        }
    };

    auto median = [&]() {
        return *minHeap.begin();
    };

    auto cost = [&]() {
        int m = median();
        // minHeap contains values greater than equal to median
        ll updateMinHeapCost = minHeapSum - (m * minHeap.size());
        ll updateMaxHeapCost = (m * maxHeap.size()) - maxHeapSum;
        return updateMinHeapCost + updateMaxHeapCost;
    };

    balance();
    cout << cost() << " ";
    for (int i = k; i < n; i++) {
        insert(arr[i]);
        erase(arr[i - k]);
        balance();
        cout << cost() << " ";
    }
    cout << endl;
}
