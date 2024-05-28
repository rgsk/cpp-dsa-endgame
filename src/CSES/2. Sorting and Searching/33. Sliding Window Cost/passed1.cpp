#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T, typename Compare = less<T>>
class Heap {
   private:
    multiset<int> st;
    // Helper type trait to check if Compare is std::greater
    static constexpr bool isMin = std::is_same<Compare, std::greater<T>>::value;

   public:
    Heap() {
    }

    void push(T v) {
        st.insert(v);
    }
    T top() {
        if (st.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        if (isMin) {
            return *st.begin();
        } else {
            return *st.rbegin();
        }
    }
    void pop() {
        if (st.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        if (isMin) {
            st.erase(st.begin());
        } else {
            st.erase(--st.end());
        }
    }
    void erase(T v) {
        st.erase(st.find(v));
    }
    size_t size() {
        return st.size();
    }
};

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
    Heap<int> maxHeap;
    Heap<int, greater<int>> minHeap;
    ll minHeapSum = 0;
    ll maxHeapSum = 0;

    for (int i = 0; i < k; i++) {
        maxHeap.push(arr[i]);
        maxHeapSum += arr[i];
    }

    auto erase = [&](int v) {
        if (v >= minHeap.top()) {
            minHeap.erase(v);
            minHeapSum -= v;
        } else {
            maxHeap.erase(v);
            maxHeapSum -= v;
        }
    };
    auto balance = [&]() {
        while (maxHeap.size() >= minHeap.size()) {
            int v = maxHeap.top();
            minHeap.push(v);
            maxHeap.erase(v);
            minHeapSum += v;
            maxHeapSum -= v;
        }
        while (minHeap.size() > maxHeap.size() + 2) {
            int v = minHeap.top();
            maxHeap.push(v);
            minHeap.erase(v);
            maxHeapSum += v;
            minHeapSum -= v;
        }
    };
    auto insert = [&](int v) {
        if (v >= minHeap.top()) {
            minHeap.push(v);
            minHeapSum += v;
        } else {
            maxHeap.push(v);
            maxHeapSum += v;
        }
    };

    auto median = [&]() {
        return minHeap.top();
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
