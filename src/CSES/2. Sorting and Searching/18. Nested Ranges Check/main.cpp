#include <bits/stdc++.h>
using namespace std;

struct Range {
    int start;
    int end;
    int index;
};

bool compare(const Range &a, const Range &b) {
    if (a.start == b.start)
        return a.end > b.end;  // Sort by end descending if start is the same
    return a.start < b.start;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<Range> ranges(n);
    vector<int> contains(n, 0);
    vector<int> isContained(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].index = i;
    }

    sort(ranges.begin(), ranges.end(), compare);

    int maxEnd = -1;
    for (int i = 0; i < n; i++) {
        if (ranges[i].end <= maxEnd) {
            isContained[ranges[i].index] = 1;
        }
        maxEnd = max(maxEnd, ranges[i].end);
    }

    int minEnd = 1e9 + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (ranges[i].end >= minEnd) {
            contains[ranges[i].index] = 1;
        }
        minEnd = min(minEnd, ranges[i].end);
    }

    for (int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << isContained[i] << " ";
    }
    cout << endl;

    return 0;
}