#include <bits/stdc++.h>
using namespace std;
list<int>::iterator get_next_cicular(list<int>::iterator it, list<int>& children) {
    it = next(it);  // Skip one child
    if (it == children.end()) {
        it = children.begin();
    }
    return it;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    list<int> children;
    for (int i = 1; i <= n; ++i) {
        children.push_back(i);
    }

    auto it = children.begin();

    while (!children.empty()) {
        // Move to the next child to be removed
        int steps = k % children.size();
        for (int i = 0; i < steps; i++) {
            it = get_next_cicular(it, children);
        }
        auto next_it = get_next_cicular(it, children);
        cout << *it << " ";
        children.erase(it);
        it = next_it;
    }

    cout << endl;
    return 0;
}
