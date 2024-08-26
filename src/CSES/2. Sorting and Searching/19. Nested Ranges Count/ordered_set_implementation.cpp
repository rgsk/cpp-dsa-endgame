// video - https://www.youtube.com/watch?v=ORdmSirqrMs&t=586s

#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Range {
    int start, end, index;
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
    vector<int> isContainedBy(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].index = i;
    }

    // Sort ranges by starting point, and by descending end point for the same start point
    sort(ranges.begin(), ranges.end(), compare);

    ordered_set<pair<int, int>> ends;

    for (int i = 0; i < n; i++) {
        // all elemeents greater than or equal to end
        isContainedBy[ranges[i].index] = ends.size() - ends.order_of_key({ranges[i].end, -1});
        ends.insert({ranges[i].end, ranges[i].index});
    }

    ends.clear();

    for (int i = n - 1; i >= 0; i--) {
        // all elemeents less than or equal to end
        contains[ranges[i].index] = ends.order_of_key({ranges[i].end + 1, -1});
        ends.insert({ranges[i].end, ranges[i].index});
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