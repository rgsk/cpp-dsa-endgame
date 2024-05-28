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

            updateIndex(heap[parent], parent, index);
            updateIndex(heap[index], index, parent);
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
            updateIndex(heap[index], index, child);
            updateIndex(heap[child], child, index);
            swap(heap[child], heap[index]);
            index = child;
        }
    }

    void updateIndex(T val, int prev, int cur) {
        indices[val].insert(cur);
        indices[val].erase(prev);
    }
    void removeIndex(T val, int index) {
        indices[val].erase(index);
    }
    void addIndex(T val, int index) {
        indices[val].insert(index);
    }
    int popIndex(T val) {
        int index = *(indices[val].begin());
        indices[val].erase(indices[val].begin());
        return index;
    }

   public:
    // Constructor
    Heap() {}

    // Constructor with initialization from a vector or array
    Heap(const vector<T>& elements, const Compare& cmp = Compare()) : heap(elements), comp(cmp) {
        for (int i = 0; i < heap.size(); ++i) {
            addIndex(heap[i], i);
        }
        // Build heap bottom-up
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    // Insertion operation
    void push(const T& val) {
        heap.push_back(val);
        addIndex(val, heap.size() - 1);
        heapifyUp(heap.size() - 1);
    }

    // Removal operation (removes the top element)
    void pop() {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        popIndex(heap.back());
        heap[0] = heap.back();
        addIndex(heap[0], 0);
        heap.pop_back();
        heapifyDown(0);
    }

    // Remove a specific element from the Heap
    void erase(const T& val) {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        // we tried to optimize erase function
        // by tracking indexes of values inside heap
        // this way we don't have to look for index of val in heap
        // at the time of erase
        // but tracking indexes takes a lot of extra time
        int index = popIndex(val);
        if (index == heap.size() - 1) {
            heap.pop_back();
        } else {
            heap[index] = heap.back();
            addIndex(heap[index], index);
            removeIndex(heap[index], heap.size() - 1);
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
