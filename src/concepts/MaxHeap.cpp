// C++ program to show that priority_queue is by
// default a Max Heap
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main() {
    // Creates a max heap
    priority_queue<int> maxHeap;
    maxHeap.push(5);
    maxHeap.push(1);
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);

    // One by one extract items from max heap
    while (maxHeap.empty() == false) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    return 0;
}