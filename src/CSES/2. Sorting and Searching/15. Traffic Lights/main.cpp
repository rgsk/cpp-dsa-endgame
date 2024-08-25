#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x, n;
    cin >> x >> n;

    set<int> positions;
    multiset<int> gaps;

    // Initial positions: start at 0 and end at x
    positions.insert(0);
    positions.insert(x);
    gaps.insert(x);  // Initially, the whole street is a single segment

    vector<int> lights(n);
    for (int i = 0; i < n; i++) {
        cin >> lights[i];
    }

    for (int i = 0; i < n; i++) {
        int p = lights[i];

        // Insert the new traffic light position
        positions.insert(p);

        // Find the position of the new light
        auto it = positions.find(p);

        // Determine the neighboring positions
        int _prev = *prev(it);
        int _next = *next(it);

        // Remove the old segment and add the new segments
        gaps.erase(gaps.find(_next - _prev));
        gaps.insert(p - _prev);
        gaps.insert(_next - p);

        // The largest segment is the last element in the multiset
        cout << *gaps.rbegin() << " ";
    }

    return 0;
}