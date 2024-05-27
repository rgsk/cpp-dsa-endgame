// C++ program to show that priority_queue is by
// default a Max Heap
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main() {
    // Creates a max heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(5);
    minHeap.push(1);
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);

    // One by one extract items from max heap
    while (minHeap.empty() == false) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}