#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    list<int> children;
    for (int i = 1; i <= n; ++i) {
        children.push_back(i);
    }

    auto it = children.begin();
    while (!children.empty()) {
        // Move to the next child to be removed
        if (it == children.end()) {
            it = children.begin();
        }
        it = next(it);  // Skip one child
        if (it == children.end()) {
            it = children.begin();
        }
        // Remove the current child and get the iterator to the next element
        cout << *it << " ";
        it = children.erase(it);
    }

    cout << endl;
    return 0;
}

// 1 2 3 4 5 6 7
// 2 4 6 1 5 3 7
