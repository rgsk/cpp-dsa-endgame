#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Alias for the PBDS tree
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    int N, K;
    cin >> N >> K;

    // Create the PBDS tree and insert children from 1 to N
    indexed_set children;
    for (int i = 1; i <= N; i++) {
        children.insert(i);
    }

    int index = 0;
    while (!children.empty()) {
        // Ensure the index wraps around the size of the current set
        index = (index + K) % children.size();  // Find the index to remove

        // Find the child at the current index and remove it
        auto it = children.find_by_order(index);
        cout << *it << " ";  // Print the removed child
        children.erase(it);
    }

    cout << endl;
    return 0;
}