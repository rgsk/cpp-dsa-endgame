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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        list<int> children;
        for (int i = 1; i <= n; ++i) {
            children.push_back(i);
        }

        auto it = children.begin();
        while (true) {
            it = get_next_cicular(it, children);
            k--;
            if (k == 0) {
                cout << *it << endl;
                break;
            }
            it = children.erase(it);
            if (it == children.end()) {
                it = children.begin();
            }
        }
    }
    return 0;
}
