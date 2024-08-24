#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Range {
    int start;
    int end;
    int index;
};

bool containsCompare(const Range &a, const Range &b) {
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
    vector<int> isContainedBy(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].index = i;
    }

    // Count "contains" using descending end points for the same start point
    sort(ranges.begin(), ranges.end(), containsCompare);

    vector<int> endTracker(n, 0);
    vector<int> freq(n, 0);

    for (int i = 0; i < n; i++) {
        // Binary search to find how many ranges this range contains
        for (int j = 0; j < i; j++) {
            if (ranges[i].end <= ranges[j].end) {
                contains[ranges[j].index]++;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (ranges[i].end >= ranges[j].end) {
                isContainedBy[ranges[j].index]++;
            }
        }
    }

    // Output the results
    for (int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << isContainedBy[i] << " ";
    }
    cout << endl;

    return 0;
}