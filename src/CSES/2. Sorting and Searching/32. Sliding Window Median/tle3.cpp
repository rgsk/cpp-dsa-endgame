#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Compare = less<T>>
class Heap {
   private:
    vector<T> heap;
    unordered_map<T, unordered_set<int>> indices;  // Map to store element indices in the heap
    Compare comp;                                  // Comparator function object

    // Helper functions to maintain the heap property
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (comp(heap[index], heap[parent]))
                break;  // Heap property satisfied

            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int child = index;

            if (leftChild < size && comp(heap[child], heap[leftChild]))
                child = leftChild;

            if (rightChild < size && comp(heap[child], heap[rightChild]))
                child = rightChild;

            if (child == index)
                break;  // Heap property satisfied
            swap(heap[child], heap[index]);
            index = child;
        }
    }

   public:
    // Constructor
    Heap() {}

    // Constructor with initialization from a vector or array
    Heap(const vector<T>& elements, const Compare& cmp = Compare()) : heap(elements), comp(cmp) {
        // Build heap bottom-up
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    // Insertion operation
    void push(const T& val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Removal operation (removes the top element)
    void pop() {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Remove a specific element from the Heap
    void erase(const T& val) {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        int index = find(heap.begin(), heap.end(), val) - heap.begin();
        if (index == heap.size()) {
            throw runtime_error("element not present in heap");
        }
        if (index == heap.size() - 1) {
            heap.pop_back();
        } else {
            heap[index] = heap.back();
            heap.pop_back();
            heapifyUp(index);
            heapifyDown(index);
        }
    }

    // Access the top element (without removing it)
    const T& top() const {
        if (!heap.empty())
            return heap[0];
        throw runtime_error("Heap is empty");
    }

    // Check if the Heap is empty
    bool empty() const {
        return heap.empty();
    }

    // Return the size of the Heap
    size_t size() const {
        return heap.size();
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

    for (int i = 0; i < k; i++) {
        maxHeap.push(arr[i]);
    }

    auto erase = [&](int v) {
        if (v >= minHeap.top()) {
            minHeap.erase(v);
        } else {
            maxHeap.erase(v);
        }
    };
    auto balance = [&]() {
        while (maxHeap.size() >= minHeap.size()) {
            int v = maxHeap.top();
            minHeap.push(v);
            maxHeap.erase(v);
        }
        while (minHeap.size() > maxHeap.size() + 2) {
            int v = minHeap.top();
            maxHeap.push(v);
            minHeap.erase(v);
        }
    };
    auto insert = [&](int v) {
        if (v >= minHeap.top()) {
            minHeap.push(v);
        } else {
            maxHeap.push(v);
        }
    };

    auto median = [&]() {
        return minHeap.top();
    };
    balance();
    cout << median() << " ";
    for (int i = k; i < n; i++) {
        insert(arr[i]);
        erase(arr[i - k]);
        balance();
        cout << median() << " ";
    }
    cout << endl;
}
