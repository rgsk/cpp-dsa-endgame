#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    // Sort movies by their ending times (and by starting times if end times are the same)
    sort(movies.begin(), movies.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });

    multiset<int> screens;  // To keep track of the end times of currently occupied screens
    for (int i = 0; i < k; i++) {
        screens.insert(0);  // Initialize k screens with end time 0
    }

    int ans = 0;

    for (const auto &movie : movies) {
        // Find the first screen that is available (i.e., whose end time is <= movie start time)
        auto it = screens.upper_bound(movie.first);
        if (it != screens.begin()) {
            --it;                          // Move to the last screen that is actually <= movie.first
            screens.erase(it);             // Remove that screen from the set
            screens.insert(movie.second);  // Insert the new end time into the set
            ans++;                         // Count this movie as scheduled
        }
    }

    cout << ans << endl;
    return 0;
}