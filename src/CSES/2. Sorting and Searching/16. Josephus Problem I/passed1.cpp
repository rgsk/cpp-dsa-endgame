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
    int n;
    cin >> n;

    list<int> children;
    for (int i = 1; i <= n; ++i) {
        children.push_back(i);
    }

    auto it = children.begin();

    while (!children.empty()) {
        // Move to the next child to be removed
        it = get_next_cicular(it, children);
        auto next_it = get_next_cicular(it, children);
        cout << *it << " ";
        children.erase(it);
        it = next_it;
    }

    cout << endl;
    return 0;
}

// 1 2 3 4 5 6 7
// 2 4 6 1 5 3 7
