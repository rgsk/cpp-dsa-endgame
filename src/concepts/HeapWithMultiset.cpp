#include <bits/stdc++.h>

using namespace std;

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
    Heap<int, greater<int>> minHeap;
    minHeap.push(5);
    minHeap.push(4);
    minHeap.push(2);
    cout << minHeap.top() << endl;
    minHeap.erase(2);
    cout << minHeap.top() << endl;
    Heap<int> maxHeap;
    maxHeap.push(5);
    maxHeap.push(4);
    maxHeap.push(2);
    cout << maxHeap.top() << endl;
    maxHeap.erase(5);
    cout << maxHeap.top() << endl;
    return 0;
}